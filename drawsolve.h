#ifndef DRAWSOLVE_H
#define DRAWSOLVE_H

#include <QDebug>
#include <QMainWindow>
#include <QObject>
#include <QtCore>
#include <QtGui>
#include <cmath>
#include "ibex.h"
#include "frame.h"
#include "sivia.h"

class DrawSolve
{
public:
    DrawSolve(Frame& frame, double epsilon, int valueScrollBar);
};

#endif // DRAWSOLVE_H
