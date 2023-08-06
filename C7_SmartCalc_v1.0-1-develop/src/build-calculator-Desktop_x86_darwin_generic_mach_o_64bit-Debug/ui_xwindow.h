/********************************************************************************
** Form generated from reading UI file 'xwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XWINDOW_H
#define UI_XWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Xwindow
{
public:
    QLineEdit *lineEdit;

    void setupUi(QWidget *Xwindow)
    {
        if (Xwindow->objectName().isEmpty())
            Xwindow->setObjectName(QString::fromUtf8("Xwindow"));
        Xwindow->resize(400, 300);
        lineEdit = new QLineEdit(Xwindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 120, 113, 21));

        retranslateUi(Xwindow);

        QMetaObject::connectSlotsByName(Xwindow);
    } // setupUi

    void retranslateUi(QWidget *Xwindow)
    {
        Xwindow->setWindowTitle(QCoreApplication::translate("Xwindow", "Form", nullptr));
        lineEdit->setText(QCoreApplication::translate("Xwindow", "hello", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Xwindow: public Ui_Xwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XWINDOW_H
