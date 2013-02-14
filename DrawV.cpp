
#include "drawv.h"
#include "sivia.h"


/** DrawV - Draws the Level Curves of the passed function in the passed frame
  * Params:
  *     Function(IBEX) func - Function according to wich the Level Curves will be drawed
  *     Frame(QT) frame - Frame where the function will draw the Level curves of the passed function func
  *     Double epsilon - Value of the accuracy of the Sivia algorithm
  */

Drawv::Drawv(Function func, Frame& frame, double epsilon)
{
    //Declare the variables x1 and x2
    Variable x1,x2;

    //Create the NumConstrait for func(x1,x2) < 0
    NumConstraint cInside_1(x1,x2, func(x1,x2)<0);
    NumConstraint cOutside_1(x1,x2, func(x1,x2)>0);

    //Create the Forward Backward Constraints
    CtcFwdBwd t1 (cInside_1);
    CtcFwdBwd t2 (cOutside_1);

    //Create the NumConstrait for func(x1,x2) > 0
    NumConstraint c4(x1, sqr(x1)>-1);
    NumConstraint c2(x1,x2, sin(10*sqrt(func(x1,x2)))=0);

    //Create the Forward Backward Constraints
    CtcFwdBwd t3 (c2);
    CtcFwdBwd t4 (c4);

    CtcUnion in(t1, t3);
    CtcCompo out(t2,t4);

    //Execute Sivia with the created constraints and draw the lines
    Sivia(frame, epsilon, IntervalVector(2,Interval(-10,10)), in, out, QColor(Qt::blue), QColor(Qt::cyan),QColor(Qt::red), QColor(Qt::magenta), QColor(Qt::blue),  QColor(Qt::blue));
}
