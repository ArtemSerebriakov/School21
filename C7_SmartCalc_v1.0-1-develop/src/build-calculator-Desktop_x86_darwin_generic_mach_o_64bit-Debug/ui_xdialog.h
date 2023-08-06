/********************************************************************************
** Form generated from reading UI file 'xdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XDIALOG_H
#define UI_XDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_XDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit_x;
    QPushButton *pushButton_x;
    QLabel *label_x;

    void setupUi(QDialog *XDialog)
    {
        if (XDialog->objectName().isEmpty())
            XDialog->setObjectName(QString::fromUtf8("XDialog"));
        XDialog->resize(170, 141);
        verticalLayout = new QVBoxLayout(XDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(XDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(14);
        label->setFont(font);
#if QT_CONFIG(tooltip)
        label->setToolTip(0u);
#endif // QT_CONFIG(tooltip)
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        lineEdit_x = new QLineEdit(XDialog);
        lineEdit_x->setObjectName(QString::fromUtf8("lineEdit_x"));

        verticalLayout->addWidget(lineEdit_x);

        pushButton_x = new QPushButton(XDialog);
        pushButton_x->setObjectName(QString::fromUtf8("pushButton_x"));
        pushButton_x->setFont(font);

        verticalLayout->addWidget(pushButton_x);

        label_x = new QLabel(XDialog);
        label_x->setObjectName(QString::fromUtf8("label_x"));
        label_x->setFont(font);
        label_x->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_x);


        retranslateUi(XDialog);

        QMetaObject::connectSlotsByName(XDialog);
    } // setupUi

    void retranslateUi(QDialog *XDialog)
    {
        XDialog->setWindowTitle(QCoreApplication::translate("XDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("XDialog", "Enter value of X", nullptr));
        pushButton_x->setText(QCoreApplication::translate("XDialog", "OK", nullptr));
        label_x->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class XDialog: public Ui_XDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XDIALOG_H
