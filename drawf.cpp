#include "drawf.h"

Drawf::Drawf(Frame& frame, double x1min, double x1max, double x2min, double x2max, int valueResolution){

    double x1, x2;

    //Paramètres de tracé des fléches
    QPen pen1;
    pen1.setStyle(Qt::SolidLine);

    pen1.setWidth(1);
    pen1.setColor(Qt::black);

    //Récupération des fonctions
    f_inf = new Function("f_inf.txt");
    f_sup = new Function("f_sup.txt");

    //Création du cadre
    for (x1=x1min;x1<=x1max;x1=x1+(double)valueResolution/10.){
        for (x2=x2min;x2<=x2max;x2=x2+(double)valueResolution/10.){

            double _xyz[2][2]={{x1,x1},{x2,x2}};
            IntervalVector xyz(2,_xyz);

            IntervalVector f1=f_inf->eval_vector(xyz);
            IntervalVector f2=f_sup->eval_vector(xyz);

            //Calcul des normes des vecteurs
            double n1=std::sqrt(std::pow(f1[0].mid(),2)+std::pow(f1[1].mid(),2));
            double n2=std::sqrt(std::pow(f2[0].mid(),2)+std::pow(f2[1].mid(),2));
            double n3=std::sqrt(std::pow(f2[0].mid(),2)+std::pow(f1[1].mid(),2));
            double n4=std::sqrt(std::pow(f1[0].mid(),2)+std::pow(f2[1].mid(),2));

            //Tracé des flèches
            frame.DrawArrow(x1,x2,f1[0].mid()/n1,f1[1].mid()/n1,0.1,pen1);
            frame.DrawArrow(x1,x2,f2[0].mid()/n2,f2[1].mid()/n2,0.1,pen1);
            frame.DrawArrow(x1,x2,f2[0].mid()/n3,f1[1].mid()/n3,0.1,pen1);
            frame.DrawArrow(x1,x2,f1[0].mid()/n4,f2[1].mid()/n4,0.1,pen1);

        }
    }

}
