#ifndef XDIALOG_H
#define XDIALOG_H

#include <QDialog>

extern "C" {
#include "validator.h"
}

namespace Ui {
class XDialog;
}

class XDialog : public QDialog {
  Q_OBJECT

 public:
  explicit XDialog(QWidget *parent = nullptr);
  ~XDialog();

 signals:
  void transmit(QString txt);

 private slots:
  void on_pushButton_x_clicked();

 private:
  Ui::XDialog *ui;
};

#endif  // XDIALOG_H
