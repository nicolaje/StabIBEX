/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Feb 13 17:17:29 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QDoubleSpinBox *EpsilonSpinBox;
    QLabel *label_Epsilon;
    QGraphicsView *graphicsView;
    QPlainTextEdit *plainTextEditV;
    QPushButton *pushButtonV;
    QPlainTextEdit *plainTextEditf_inf;
    QPlainTextEdit *plainTextEditf_sup;
    QPushButton *pushButtonf_inf;
    QPushButton *pushButtonf_sup;
    QSlider *vscrollbar;
    QLabel *label1;
    QPushButton *DrawV;
    QPlainTextEdit *plainTextEditgradV;
    QPushButton *pushButtongradV;
    QPushButton *DrawF;
    QCheckBox *trajc;
    QPushButton *pushButtonSolve;
    QSlider *verticalSliderResolution;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(791, 622);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        EpsilonSpinBox = new QDoubleSpinBox(centralWidget);
        EpsilonSpinBox->setObjectName(QString::fromUtf8("EpsilonSpinBox"));
        EpsilonSpinBox->setGeometry(QRect(30, 30, 71, 22));
        EpsilonSpinBox->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        EpsilonSpinBox->setDecimals(4);
        EpsilonSpinBox->setMinimum(0.01);
        EpsilonSpinBox->setMaximum(1);
        EpsilonSpinBox->setSingleStep(0.1);
        EpsilonSpinBox->setValue(0.1);
        label_Epsilon = new QLabel(centralWidget);
        label_Epsilon->setObjectName(QString::fromUtf8("label_Epsilon"));
        label_Epsilon->setGeometry(QRect(40, 0, 61, 21));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(140, 50, 391, 491));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEditV = new QPlainTextEdit(centralWidget);
        plainTextEditV->setObjectName(QString::fromUtf8("plainTextEditV"));
        plainTextEditV->setGeometry(QRect(610, 10, 181, 91));
        pushButtonV = new QPushButton(centralWidget);
        pushButtonV->setObjectName(QString::fromUtf8("pushButtonV"));
        pushButtonV->setGeometry(QRect(530, 40, 80, 24));
        plainTextEditf_inf = new QPlainTextEdit(centralWidget);
        plainTextEditf_inf->setObjectName(QString::fromUtf8("plainTextEditf_inf"));
        plainTextEditf_inf->setGeometry(QRect(610, 110, 181, 91));
        plainTextEditf_sup = new QPlainTextEdit(centralWidget);
        plainTextEditf_sup->setObjectName(QString::fromUtf8("plainTextEditf_sup"));
        plainTextEditf_sup->setGeometry(QRect(610, 220, 181, 91));
        pushButtonf_inf = new QPushButton(centralWidget);
        pushButtonf_inf->setObjectName(QString::fromUtf8("pushButtonf_inf"));
        pushButtonf_inf->setGeometry(QRect(530, 130, 80, 24));
        pushButtonf_sup = new QPushButton(centralWidget);
        pushButtonf_sup->setObjectName(QString::fromUtf8("pushButtonf_sup"));
        pushButtonf_sup->setGeometry(QRect(530, 240, 80, 24));
        vscrollbar = new QSlider(centralWidget);
        vscrollbar->setObjectName(QString::fromUtf8("vscrollbar"));
        vscrollbar->setGeometry(QRect(30, 240, 20, 201));
        vscrollbar->setMinimum(0);
        vscrollbar->setMaximum(10);
        vscrollbar->setOrientation(Qt::Vertical);
        label1 = new QLabel(centralWidget);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(30, 450, 21, 20));
        DrawV = new QPushButton(centralWidget);
        DrawV->setObjectName(QString::fromUtf8("DrawV"));
        DrawV->setGeometry(QRect(30, 90, 80, 24));
        plainTextEditgradV = new QPlainTextEdit(centralWidget);
        plainTextEditgradV->setObjectName(QString::fromUtf8("plainTextEditgradV"));
        plainTextEditgradV->setGeometry(QRect(610, 330, 181, 101));
        pushButtongradV = new QPushButton(centralWidget);
        pushButtongradV->setObjectName(QString::fromUtf8("pushButtongradV"));
        pushButtongradV->setGeometry(QRect(530, 360, 80, 24));
        DrawF = new QPushButton(centralWidget);
        DrawF->setObjectName(QString::fromUtf8("DrawF"));
        DrawF->setGeometry(QRect(30, 130, 80, 24));
        trajc = new QCheckBox(centralWidget);
        trajc->setObjectName(QString::fromUtf8("trajc"));
        trajc->setGeometry(QRect(660, 470, 81, 17));
        pushButtonSolve = new QPushButton(centralWidget);
        pushButtonSolve->setObjectName(QString::fromUtf8("pushButtonSolve"));
        pushButtonSolve->setGeometry(QRect(30, 170, 80, 24));
        verticalSliderResolution = new QSlider(centralWidget);
        verticalSliderResolution->setObjectName(QString::fromUtf8("verticalSliderResolution"));
        verticalSliderResolution->setGeometry(QRect(90, 240, 16, 201));
        verticalSliderResolution->setMinimum(5);
        verticalSliderResolution->setMaximum(20);
        verticalSliderResolution->setPageStep(1);
        verticalSliderResolution->setSliderPosition(5);
        verticalSliderResolution->setOrientation(Qt::Vertical);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(72, 450, 61, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 791, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label_Epsilon->setText(QApplication::translate("MainWindow", "Accuracy", 0, QApplication::UnicodeUTF8));
        plainTextEditV->setPlainText(QApplication::translate("MainWindow", "function V(x1,x2)\n"
"   return( \n"
"   0.5*x2^2-cos(x1)\n"
"   );\n"
"end		 ", 0, QApplication::UnicodeUTF8));
        pushButtonV->setText(QApplication::translate("MainWindow", "use V", 0, QApplication::UnicodeUTF8));
        plainTextEditf_inf->setPlainText(QApplication::translate("MainWindow", "function f_inf(x1,x2)\n"
"   return( \n"
"   x2-0.1;\n"
"   -sin(x1)-x2-0.1\n"
"   );\n"
"end		 ", 0, QApplication::UnicodeUTF8));
        plainTextEditf_sup->setPlainText(QApplication::translate("MainWindow", "function f_sup(x1,x2)\n"
"   return( \n"
"   x2+0.1;\n"
"   -sin(x1)-x2+0.1\n"
"   );\n"
"end		 ", 0, QApplication::UnicodeUTF8));
        pushButtonf_inf->setText(QApplication::translate("MainWindow", "use f_inf", 0, QApplication::UnicodeUTF8));
        pushButtonf_sup->setText(QApplication::translate("MainWindow", "use f_sup", 0, QApplication::UnicodeUTF8));
        label1->setText(QApplication::translate("MainWindow", "v+", 0, QApplication::UnicodeUTF8));
        DrawV->setText(QApplication::translate("MainWindow", "DrawV", 0, QApplication::UnicodeUTF8));
        plainTextEditgradV->setPlainText(QApplication::translate("MainWindow", "function gradV(x1,x2)\n"
"   return( \n"
"   -sin(x1);\n"
"   x2\n"
"   );\n"
"end		 ", 0, QApplication::UnicodeUTF8));
        pushButtongradV->setText(QApplication::translate("MainWindow", "use gradV", 0, QApplication::UnicodeUTF8));
        DrawF->setText(QApplication::translate("MainWindow", "DrawF", 0, QApplication::UnicodeUTF8));
        trajc->setText(QApplication::translate("MainWindow", "trajectory", 0, QApplication::UnicodeUTF8));
        pushButtonSolve->setText(QApplication::translate("MainWindow", "DrawVstable", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "resolution", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
