#ifndef SIVIA_H
#define SIVIA_H

#include "frame.h"
#include "ibex.h"

using namespace ibex;
using namespace std;

class Sivia {
public:

    /*
     * Run the SIVIA algorithm.
     *
     * Parameters:
     * frame:   where to draw the boxes.
     * box: the box to contract/bissect
     * epsilon: precision downto which boxes are bisected.
     */
    Sivia(Frame& frame, double epsilon, IntervalVector box, Ctc& Coutside, Ctc& Cinside, QColor PenOutside,
                 QColor BrushOutside, QColor PenInside, QColor BrushInside, QColor PenSmallEnough, QColor BrushSmallEnough );

    /*
     * Contract "box" with "c" and draw the trace (i.e., the difference between box and c(box))
     * with the colors "pencolor" and "brushcolor".
     */
    void contract_and_draw(Ctc& c, IntervalVector& box,  const QColor & pencolor, const QColor & brushcolor);


private:
    Frame& frame;
};

#endif // SIVIA_H
