#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cstring>
#include <iostream>

#include "ui_mainwindow.h"
#include "xdialog.h"

extern "C" {
#include "stack.h"
#include "validator.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_pushButton_0_clicked();

  void on_pushButton_1_clicked();

  void on_lineEdit_textEdited();

  void on_pushButton_2_clicked();

  void on_pushButton_3_clicked();

  void on_pushButton_4_clicked();

  void on_pushButton_5_clicked();

  void on_pushButton_6_clicked();

  void on_pushButton_7_clicked();

  void on_pushButton_8_clicked();

  void on_pushButton_9_clicked();

  void on_pushButton_acos_clicked();

  void on_pushButton_again_clicked();

  void on_pushButton_asin_clicked();

  void on_pushButton_atan_clicked();

  void on_pushButton_calculate_clicked();

  void on_pushButton_cos_clicked();

  void on_pushButton_div_clicked();

  void on_pushButton_left_bracket_clicked();

  void on_pushButton_ln_clicked();

  void on_pushButton_log_clicked();

  void on_pushButton_minus_clicked();

  void on_pushButton_mod_clicked();

  void on_pushButton_mult_clicked();

  void on_pushButton_plus_clicked();

  void on_pushButton_point_clicked();

  void on_pushButton_pow_clicked();

  void on_pushButton_right_bracket_clicked();

  void on_pushButton_sin_clicked();

  void on_pushButton_tan_clicked();

  void on_pushButton_x_clicked();

  void on_pushButton_graph_clicked();

  void on_pushButton_plus_minus_clicked();

  void on_pushButton_sqrt_clicked();

  void update(QString txt);

 private:
  Ui::MainWindow *ui;
  double xBegin, xEnd, h, X;
  int N;
  char temp_str[255];
  QString text_str;
  QVector<double> x, y;
  XDialog *x1;
};
#endif  // MAINWINDOW_H
