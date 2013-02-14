#include "drawsolve.h"



DrawSolve::DrawSolve(Frame& frame, double epsilon, int valueScrollBar)
{
    // Create the function we want to apply SIVIA on.
    Variable x1,x2,a1,a2;

//    double v_bar = (double)valueScrollBar;

    Function V("V.txt");
    Function f_sup("f_sup.txt");
    Function f_inf("f_inf.txt");

    Function dV("gradV.txt");

    NumConstraint c1_cIn(x1,x2,a1,a2,a1*dV(x1,x2)[0]+a2*dV(x1,x2)[1]>=0);

    NumConstraint c21_cIn(x1,x2,a1,a2,f_sup(x1,x2)[0]-a1<0);
    NumConstraint c22_cIn(x1,x2,a1,a2,f_sup(x1,x2)[1]-a2<0);

    NumConstraint c31_cIn(x1,x2,a1,a2,a1-f_inf(x1,x2)[0]<0);
    NumConstraint c32_cIn(x1,x2,a1,a2,a2-f_inf(x1,x2)[1]<0);

    NumConstraint c41_cIn(x1,x2,V(x1,x2)<0);
    NumConstraint c42_cIn(x1,x2,V(x1,x2)>valueScrollBar);

    CtcFwdBwd c1_In(c1_cIn);

    CtcFwdBwd c21_In(c21_cIn);
    CtcFwdBwd c22_In(c22_cIn);
    CtcUnion c2_In(c21_In, c22_In);

    CtcFwdBwd c31_In(c31_cIn);
    CtcFwdBwd c32_In(c32_cIn);
    CtcUnion c3_In(c31_In, c32_In);

    CtcFwdBwd c41_In(c41_cIn);
    CtcFwdBwd c42_In(c42_cIn);
    CtcUnion c4_In(c41_In, c42_In);

    CtcUnion cIn1(c1_In, c2_In);
    CtcUnion cIn2(c3_In, c4_In);

    CtcUnion cIn(cIn1, cIn2);

    NumConstraint c1_c(x1,x2,a1,a2,a1*dV(x1,x2)[0]+a2*dV(x1,x2)[1]>=0);

    NumConstraint c21_c(x1,x2,a1,a2,f_sup(x1,x2)[0]-a1>=0);
    NumConstraint c22_c(x1,x2,a1,a2,f_sup(x1,x2)[1]-a2>=0);

    NumConstraint c31_c(x1,x2,a1,a2,a1-f_inf(x1,x2)[0]>=0);
    NumConstraint c32_c(x1,x2,a1,a2,a2-f_inf(x1,x2)[1]>=0);

    NumConstraint c41_c(x1,x2,V(x1,x2)>=0);
    NumConstraint c42_c(x1,x2,V(x1,x2)<=valueScrollBar);

    CtcFwdBwd c1(c1_c);

    CtcFwdBwd c21(c21_c);
    CtcFwdBwd c22(c22_c);
    CtcCompo c2(c21,c22);

    CtcFwdBwd c31(c31_c);
    CtcFwdBwd c32(c32_c);
    CtcCompo c3(c31, c32);

    CtcFwdBwd c41(c41_c);
    CtcFwdBwd c42(c42_c);
    CtcCompo c4(c41,c42);

    CtcCompo cOut1(c1,c2);
    CtcCompo cOut2(c3,c4);

    CtcCompo cOut(cOut1,cOut2);

    // Build the initial box.
    IntervalVector box(4);
    box[0]=Interval(-10,10);
    box[1]=Interval(-10,10);
    box[2]=Interval::ALL_REALS;
    box[3]=Interval::ALL_REALS;

    Sivia captureSet(frame, epsilon, box, cOut, cIn, QColor(Qt::blue), QColor(Qt::cyan),QColor(Qt::red), QColor(Qt::magenta), QColor(Qt::yellow),  QColor(Qt::yellow));
}


