#ifndef SIMU_H
#define SIMU_H
#include "frame.h"
#include "ibex.h"

using namespace ibex;
using namespace std;

class Simu
{
public:
    Simu (char *ti, char *ts,Frame& frame,double x10, double x20);
    double get_random();

private:
        //Frame& frame;
};

#endif // SIMU_H
