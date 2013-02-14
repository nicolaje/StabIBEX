#ifndef DRAWV_H
#define DRAWV_H

#include "frame.h"
#include "ibex.h"

using namespace ibex;
using namespace std;

class Drawv {
public:

    /*
     * Run the SIVIA algorithm.
     *
     * Parameters:
     * frame:   where to draw the boxes.
     * epsilon: precision downto which boxes are bisected.
     */
    Drawv(Function func, Frame& frame, double epsilon);

};

#endif // SIVIA_H

