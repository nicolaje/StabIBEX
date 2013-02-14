#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cmath>
#include "ibex.h"
#include "sivia.h"
#include "drawv.h"
#include "simu.h"
#include "drawf.h"


double epsilon;
int vResAnc=0;
int in = 0;


MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

}

void MainWindow::Init() {
    epsilon=ui->EpsilonSpinBox->value();
    ui->graphicsView->setInteractive(true);
    xmin = -10;
    xmax = 10;
    ymin = -10;
    ymax = 10;
    frame = new Frame(this,ui->graphicsView,xmin,xmax,ymin,ymax);
    in++;
}

MainWindow::~MainWindow() {
    delete ui;
}



void MainWindow::on_pushButtonV_clicked()
{
    QString s1 = ui->plainTextEditV->toPlainText();

    QFile file("V.txt");
         if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
             return;

         QTextStream out(&file);
         out << s1 << "\n";
         file.close();
}

void MainWindow::on_pushButtonf_inf_clicked()
{
    QString s2 = ui->plainTextEditf_inf->toPlainText();

    QFile file("f_inf.txt");
         if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
             return;

         QTextStream out(&file);
         out << s2 << "\n";
         file.close();
}

void MainWindow::on_pushButtonf_sup_clicked()
{
    QString s3 = ui->plainTextEditf_sup->toPlainText();

    QFile file("f_sup.txt");
         if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
             return;

         QTextStream out(&file);
         out << s3 << "\n";
         file.close();
}

void MainWindow::on_pushButtongradV_clicked()
{
    QString s4 = ui->plainTextEditgradV->toPlainText();

    QFile file("gradV.txt");
         if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
             return;

         QTextStream out(&file);
         out << s4 << "\n";
         file.close();

}

void MainWindow::on_DrawV_clicked()
{
    if(in == 0){
        Init();
    }

    on_pushButtonV_clicked();

    Function v("V.txt");

    // run SIVIA
    Drawv tmp(v, *frame, epsilon);

}

void MainWindow::mousePressEvent(QMouseEvent *mouseEvent)
{

    mouseEvent->accept(); //j'accepte l'evenement
    if (mouseEvent->button() != Qt::LeftButton)
        return;
    else
    {
        if(ui->trajc->isChecked()){
            double xM = (double) (mouseEvent->x()-140)/(391/20) -10;
            double yM = (double) -(mouseEvent->y()-50)/(491/20) +10;
            Simu simulation("f_inf.txt","f_sup.txt",*frame,xM,yM);
        }
    }
}


void MainWindow::on_DrawF_clicked()
{
    if(in == 0){
        Init();
    }

    on_pushButtonf_inf_clicked();
    on_pushButtonf_sup_clicked();

    Drawf(*frame,xmin,xmax,ymin,ymax, ui->verticalSliderResolution->value());

    vResAnc =  ui->verticalSliderResolution->value();
}

void MainWindow::on_pushButtonSolve_clicked()
{

    Init();

    on_pushButtonV_clicked();
    on_pushButtonf_inf_clicked();
    on_pushButtonf_sup_clicked();
    on_pushButtongradV_clicked();

    DrawSolve(*frame, epsilon, ui->vscrollbar->value());

}
