#include "sivia.h"

void Sivia::contract_and_draw(Ctc& c, IntervalVector& box, const QColor & pencolor, const QColor & brushcolor) {
    IntervalVector initbox=box;       // get a copy
     try {
         c.contract(box);
         if (box==initbox) return;     // nothing contracted.
         IntervalVector* rest;
         int n=initbox.diff(box,rest); // calculate the set difference
         for (int i=0; i<n; i++)
         {     // display the boxes
             frame.DrawBox(rest[i][0],rest[i][1],QPen(pencolor),QBrush(brushcolor));
         }
         delete[] rest;
     } catch(EmptyBoxException&) {
         frame.DrawBox(initbox[0],initbox[1],QPen(pencolor),QBrush(brushcolor));
     }
}


//Sivia::Sivia(Frame& frame, double epsilon, Ctc& Coutside, Ctc& Cinside, QColor PenOutside,
//             QColor BrushOutside, QColor PenInside, QColor BrushInside, QColor PenSmallEnough, QColor BrushSmallEnough ) : frame(frame) {

//    // Build the initial box.
//    IntervalVector box(2);
//    box[0]=Interval(-10,10);
//    box[1]=Interval(-10,10);

//    // Build the way boxes will be bisected.
//    // "LargestFirst" means that the dimension bisected
//    // is always the largest one.
//    LargestFirst lf;

//    stack<IntervalVector> s;
//    s.push(box);

//    while (!s.empty()) {
//        // Get a copy of the current box (on top of the stack)
//        IntervalVector box=s.top();

//        // Remove the box from the stack
//        s.pop();
//        try {
//            // Remove the part that is outside
//            contract_and_draw(Coutside,box,PenOutside,BrushOutside);
//            if (box.is_empty()) { continue; }

//            // Remove the part that is inside
//            contract_and_draw(Cinside,box,PenInside,BrushInside);
//            if (box.is_empty()) { continue; }

//            // Check if the box is small enough
//            if (box.max_diam()<epsilon) {
//                frame.DrawBox(box[0],box[1],PenSmallEnough,BrushSmallEnough);
//            } else {
//                // otherwise, bisect it and
//                // push the two subboxes on the stack.
//                pair<IntervalVector,IntervalVector> boxes=lf.bisect(box);
//                s.push(boxes.first);
//                s.push(boxes.second);
//            }
//        } catch(EmptyBoxException&) { }
//    }

//    frame.Save("paving");
//}

Sivia::Sivia(Frame& frame, double epsilon, IntervalVector box, Ctc& Coutside, Ctc& Cinside, QColor PenOutside,
             QColor BrushOutside, QColor PenInside, QColor BrushInside, QColor PenSmallEnough, QColor BrushSmallEnough ) : frame(frame) {

    // Build the way boxes will be bisected.
    // "LargestFirst" means that the dimension bisected
    // is always the largest one.
    LargestFirst lf;

    stack<IntervalVector> s;
    s.push(box);

    while (!s.empty()) {
        // Get a copy of the current box (on top of the stack)
        IntervalVector box=s.top();

        // Remove the box from the stack
        s.pop();
        try {
            // Remove the part that is outside
            contract_and_draw(Coutside,box,PenOutside,BrushOutside);
            if (box.is_empty()) { continue; }

            // Remove the part that is inside
            contract_and_draw(Cinside,box,PenInside,BrushInside);
            if (box.is_empty()) { continue; }

            // Check if the box is small enough
            if (box.max_diam()<epsilon) {
                frame.DrawBox(box[0],box[1],PenSmallEnough,BrushSmallEnough);
            } else {
                // otherwise, bisect it and
                // push the two subboxes on the stack.
                pair<IntervalVector,IntervalVector> boxes=lf.bisect(box);
                s.push(boxes.first);
                s.push(boxes.second);
            }
        } catch(EmptyBoxException&) { }
    }

    frame.Save("paving");
}
