/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit;
    QPushButton *pushButton_calculate;
    QCustomPlot *widget;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_again;
    QGridLayout *gridLayout;
    QPushButton *pushButton_1;
    QPushButton *pushButton_left_bracket;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_3;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_log;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_plus_minus;
    QPushButton *pushButton_6;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_4;
    QPushButton *pushButton_point;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_2;
    QPushButton *pushButton_0;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_div;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton_right_bracket;
    QPushButton *pushButton_9;
    QPushButton *pushButton_mult;
    QPushButton *pushButton_pow;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_x;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QDoubleSpinBox *d_f_1;
    QDoubleSpinBox *d_f_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QDoubleSpinBox *e_f_1;
    QDoubleSpinBox *e_f_2;
    QPushButton *pushButton_graph;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(890, 813);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(18);
        font.setBold(true);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetFixedSize);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMaximumSize(QSize(16777200, 16777215));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(14);
        lineEdit->setFont(font1);

        horizontalLayout_5->addWidget(lineEdit);

        pushButton_calculate = new QPushButton(centralwidget);
        pushButton_calculate->setObjectName(QString::fromUtf8("pushButton_calculate"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_calculate->sizePolicy().hasHeightForWidth());
        pushButton_calculate->setSizePolicy(sizePolicy1);
        pushButton_calculate->setFont(font);
        pushButton_calculate->setIconSize(QSize(16, 16));

        horizontalLayout_5->addWidget(pushButton_calculate);

        horizontalLayout_5->setStretch(0, 3);
        horizontalLayout_5->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_5);

        widget = new QCustomPlot(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout_3->addWidget(widget);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_again = new QPushButton(centralwidget);
        pushButton_again->setObjectName(QString::fromUtf8("pushButton_again"));
        pushButton_again->setFont(font);

        verticalLayout_2->addWidget(pushButton_again);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setFont(font1);

        gridLayout->addWidget(pushButton_1, 0, 1, 1, 1);

        pushButton_left_bracket = new QPushButton(centralwidget);
        pushButton_left_bracket->setObjectName(QString::fromUtf8("pushButton_left_bracket"));
        pushButton_left_bracket->setFont(font1);

        gridLayout->addWidget(pushButton_left_bracket, 1, 5, 1, 1);

        pushButton_atan = new QPushButton(centralwidget);
        pushButton_atan->setObjectName(QString::fromUtf8("pushButton_atan"));
        pushButton_atan->setFont(font1);

        gridLayout->addWidget(pushButton_atan, 4, 5, 1, 1);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font1);

        gridLayout->addWidget(pushButton_3, 0, 3, 1, 1);

        pushButton_minus = new QPushButton(centralwidget);
        pushButton_minus->setObjectName(QString::fromUtf8("pushButton_minus"));
        pushButton_minus->setFont(font1);

        gridLayout->addWidget(pushButton_minus, 2, 2, 1, 1);

        pushButton_log = new QPushButton(centralwidget);
        pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
        pushButton_log->setFont(font1);

        gridLayout->addWidget(pushButton_log, 3, 1, 1, 1);

        pushButton_sin = new QPushButton(centralwidget);
        pushButton_sin->setObjectName(QString::fromUtf8("pushButton_sin"));
        pushButton_sin->setFont(font1);

        gridLayout->addWidget(pushButton_sin, 3, 3, 1, 1);

        pushButton_plus_minus = new QPushButton(centralwidget);
        pushButton_plus_minus->setObjectName(QString::fromUtf8("pushButton_plus_minus"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Times New Roman")});
        font2.setPointSize(14);
        font2.setKerning(true);
        pushButton_plus_minus->setFont(font2);

        gridLayout->addWidget(pushButton_plus_minus, 4, 2, 1, 1);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setFont(font1);

        gridLayout->addWidget(pushButton_6, 0, 6, 1, 1);

        pushButton_acos = new QPushButton(centralwidget);
        pushButton_acos->setObjectName(QString::fromUtf8("pushButton_acos"));
        pushButton_acos->setFont(font1);

        gridLayout->addWidget(pushButton_acos, 4, 4, 1, 1);

        pushButton_cos = new QPushButton(centralwidget);
        pushButton_cos->setObjectName(QString::fromUtf8("pushButton_cos"));
        pushButton_cos->setFont(font1);

        gridLayout->addWidget(pushButton_cos, 3, 4, 1, 1);

        pushButton_mod = new QPushButton(centralwidget);
        pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
        pushButton_mod->setFont(font1);

        gridLayout->addWidget(pushButton_mod, 2, 6, 1, 1);

        pushButton_plus = new QPushButton(centralwidget);
        pushButton_plus->setObjectName(QString::fromUtf8("pushButton_plus"));
        pushButton_plus->setFont(font1);

        gridLayout->addWidget(pushButton_plus, 2, 1, 1, 1);

        pushButton_ln = new QPushButton(centralwidget);
        pushButton_ln->setObjectName(QString::fromUtf8("pushButton_ln"));
        pushButton_ln->setFont(font1);

        gridLayout->addWidget(pushButton_ln, 3, 2, 1, 1);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setFont(font1);

        gridLayout->addWidget(pushButton_4, 0, 4, 1, 1);

        pushButton_point = new QPushButton(centralwidget);
        pushButton_point->setObjectName(QString::fromUtf8("pushButton_point"));
        pushButton_point->setFont(font1);

        gridLayout->addWidget(pushButton_point, 3, 6, 1, 1);

        pushButton_asin = new QPushButton(centralwidget);
        pushButton_asin->setObjectName(QString::fromUtf8("pushButton_asin"));
        pushButton_asin->setFont(font1);

        gridLayout->addWidget(pushButton_asin, 4, 3, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font1);

        gridLayout->addWidget(pushButton_2, 0, 2, 1, 1);

        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setFont(font1);

        gridLayout->addWidget(pushButton_0, 1, 4, 1, 1);

        pushButton_tan = new QPushButton(centralwidget);
        pushButton_tan->setObjectName(QString::fromUtf8("pushButton_tan"));
        pushButton_tan->setFont(font1);

        gridLayout->addWidget(pushButton_tan, 3, 5, 1, 1);

        pushButton_div = new QPushButton(centralwidget);
        pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
        pushButton_div->setFont(font1);

        gridLayout->addWidget(pushButton_div, 2, 4, 1, 1);

        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setFont(font1);

        gridLayout->addWidget(pushButton_8, 1, 2, 1, 1);

        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setFont(font1);

        gridLayout->addWidget(pushButton_7, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setFont(font1);

        gridLayout->addWidget(pushButton_5, 0, 5, 1, 1);

        pushButton_right_bracket = new QPushButton(centralwidget);
        pushButton_right_bracket->setObjectName(QString::fromUtf8("pushButton_right_bracket"));
        pushButton_right_bracket->setFont(font1);

        gridLayout->addWidget(pushButton_right_bracket, 1, 6, 1, 1);

        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setFont(font1);

        gridLayout->addWidget(pushButton_9, 1, 3, 1, 1);

        pushButton_mult = new QPushButton(centralwidget);
        pushButton_mult->setObjectName(QString::fromUtf8("pushButton_mult"));
        pushButton_mult->setFont(font1);

        gridLayout->addWidget(pushButton_mult, 2, 3, 1, 1);

        pushButton_pow = new QPushButton(centralwidget);
        pushButton_pow->setObjectName(QString::fromUtf8("pushButton_pow"));
        pushButton_pow->setFont(font1);

        gridLayout->addWidget(pushButton_pow, 2, 5, 1, 1);

        pushButton_sqrt = new QPushButton(centralwidget);
        pushButton_sqrt->setObjectName(QString::fromUtf8("pushButton_sqrt"));
        pushButton_sqrt->setFont(font1);

        gridLayout->addWidget(pushButton_sqrt, 4, 6, 1, 1);

        pushButton_x = new QPushButton(centralwidget);
        pushButton_x->setObjectName(QString::fromUtf8("pushButton_x"));
        pushButton_x->setFont(font1);
        pushButton_x->setIconSize(QSize(100, 100));

        gridLayout->addWidget(pushButton_x, 4, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        horizontalLayout_6->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        d_f_1 = new QDoubleSpinBox(centralwidget);
        d_f_1->setObjectName(QString::fromUtf8("d_f_1"));
        d_f_1->setReadOnly(false);
        d_f_1->setProperty("showGroupSeparator", QVariant(false));
        d_f_1->setDecimals(3);
        d_f_1->setMinimum(-1000000.000000000000000);
        d_f_1->setMaximum(1000000.000000000000000);
        d_f_1->setValue(-10.000000000000000);

        horizontalLayout_2->addWidget(d_f_1);

        d_f_2 = new QDoubleSpinBox(centralwidget);
        d_f_2->setObjectName(QString::fromUtf8("d_f_2"));
        d_f_2->setDecimals(3);
        d_f_2->setMinimum(-1000000.000000000000000);
        d_f_2->setMaximum(1000000.000000000000000);
        d_f_2->setValue(10.000000000000000);

        horizontalLayout_2->addWidget(d_f_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        e_f_1 = new QDoubleSpinBox(centralwidget);
        e_f_1->setObjectName(QString::fromUtf8("e_f_1"));
        e_f_1->setDecimals(3);
        e_f_1->setMinimum(-1000000.000000000000000);
        e_f_1->setMaximum(1000000.000000000000000);
        e_f_1->setValue(-10.000000000000000);

        horizontalLayout->addWidget(e_f_1);

        e_f_2 = new QDoubleSpinBox(centralwidget);
        e_f_2->setObjectName(QString::fromUtf8("e_f_2"));
        e_f_2->setDecimals(3);
        e_f_2->setMinimum(-1000000.000000000000000);
        e_f_2->setMaximum(1000000.000000000000000);
        e_f_2->setValue(10.000000000000000);

        horizontalLayout->addWidget(e_f_2);


        verticalLayout->addLayout(horizontalLayout);

        pushButton_graph = new QPushButton(centralwidget);
        pushButton_graph->setObjectName(QString::fromUtf8("pushButton_graph"));
        pushButton_graph->setFont(font1);

        verticalLayout->addWidget(pushButton_graph);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 2);

        horizontalLayout_6->addLayout(verticalLayout);

        horizontalLayout_6->setStretch(0, 3);

        verticalLayout_3->addLayout(horizontalLayout_6);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 5);
        verticalLayout_3->setStretch(2, 3);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 890, 24));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_calculate->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        pushButton_again->setText(QCoreApplication::translate("MainWindow", "Try again", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_left_bracket->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        pushButton_plus_minus->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_point->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        pushButton_div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_right_bracket->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_mult->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_pow->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        pushButton_x->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "X(min):X(max)", nullptr));
        d_f_1->setSpecialValueText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Y(min):Y(max)", nullptr));
        pushButton_graph->setText(QCoreApplication::translate("MainWindow", "graph", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200, \320\272\320\276\321\202\320\276\321\200\321\213\320\271 \320\275\320\265 \320\267\320\260\320\272\321\200\321\213\320\273\321\201\321\217 \320\262 \320\272\320\276\320\275\321\206\320\265 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
