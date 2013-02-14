#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDebug>
#include <QMainWindow>
#include <QEvent>
#include <QGraphicsSceneEvent>
#include <QMouseEvent>
#include "frame.h"
#include "drawsolve.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    void Init();
    Frame* frame;
    Frame* frameV;
    // Build the frame
    double xmin;
    double xmax;
    double ymin;
    double ymax;



private:
    Ui::MainWindow *ui;

signals:


private slots:
    void on_pushButtonSolve_clicked();
    void on_pushButtonV_clicked();
    void on_pushButtonf_inf_clicked();
    void on_pushButtonf_sup_clicked();
    void on_pushButtongradV_clicked();
    void on_DrawV_clicked();
    void on_DrawF_clicked();
    void on_DrawTraj_checked(QMouseEvent *mouseEvent);
};



#endif // MAINWINDOW_H
