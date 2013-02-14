
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

    //Execute Sivia with the created constraints and draw the lines
    Sivia captureSet(frame, epsilon, t1,t2, QColor(Qt::blue), QColor(Qt::cyan),QColor(Qt::red), QColor(Qt::magenta), QColor(Qt::blue),  QColor(Qt::blue)  );

    //Create the NumConstrait for func(x1,x2) > 0
    NumConstraint c4(x1, sqr(x1)>-1);
    NumConstraint c2(x1,x2, sin(10*sqrt(func(x1,x2)))=0);
    //Create the Forward Backward Constraints
    CtcFwdBwd t3 (c2);
    CtcFwdBwd t4 (c4);
    //Execute Sivia with the created constraints and draw the lines
    Sivia LevelSet(frame, epsilon, t3, t4, QColor(Qt::transparent), QColor(Qt::transparent),QColor(Qt::transparent), QColor(Qt::transparent), QColor(Qt::blue),  QColor(Qt::blue)  );

}