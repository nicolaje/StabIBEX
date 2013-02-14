#include "simu.h"
#include "sivia.h"



Simu::Simu(char *ti, char *ts,Frame& frame,double x10, double x20)
{
    //Time step
    double dt=0.1;
    //Position vector x = (x1,x2)
    Vector x(2);
    x[0]=x10;
    x[1]=x20;
    QPen pen1;  pen1.setStyle(Qt::SolidLine); pen1.setWidth(2); pen1.setColor(Qt::darkRed);
    //Definition of f+ and f-
    //Function f_inf("Pendule/f_inf.txt");
    //Function f_sup("Pendule/f_sup.txt");

    Function f_inf(ti);
    Function f_sup(ts);

    IntervalVector F(2);
    IntervalVector v1(2);
    IntervalVector v2(2);

    for (double t=0;t<500;t=t+dt){

        //definition of xtemp = current position
        double t[2][2]= {{x[0],x[0]},{x[1],x[1]}};
        IntervalVector xtemp(2,t);
        //cout << "xtemp : " << xtemp << endl;

        //Calculation of min and max points
        v1 = f_inf.eval_vector(xtemp);
        v2 = f_sup.eval_vector(xtemp);

        //Creation of trust intervals on x1 and x2 axis
        Interval f0(v1[0].mid(),v2[0].mid());
        Interval f1(v1[1].mid(),v2[1].mid());

        F[0] = f0;
        F[1] = f1;

        //Random value in the trust position box
        Vector v = F.random();
        Vector xp=x+dt*v;

        //cout << "xp : " << xp << endl;
        //Draw the line between old and new positions
        frame.DrawLine(x[0],x[1],xp[0],xp[1],pen1);

        //Set the new position
        x = xp;
    }

}
double Simu::get_random() {
    return 0.2 * ((double) rand() / (double) RAND_MAX) - 0.1;
 }
