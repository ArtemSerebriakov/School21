#include "mainwindow.h"

#include <cstring>
#include <iostream>

#include "ui_mainwindow.h"

extern "C" {
#include "polish.h"
#include "stack.h"
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  x1 = new XDialog(this);
  connect(x1, &XDialog::transmit, this, &MainWindow::update);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_log_clicked() { ui->lineEdit->insert("log"); }

void MainWindow::on_pushButton_1_clicked() { ui->lineEdit->insert("1"); }

void MainWindow::on_lineEdit_textEdited() {}

void MainWindow::on_pushButton_5_clicked() { ui->lineEdit->insert("5"); }

void MainWindow::on_pushButton_asin_clicked() { ui->lineEdit->insert("asin"); }

void MainWindow::on_pushButton_6_clicked() { ui->lineEdit->insert("6"); }

void MainWindow::on_pushButton_2_clicked() { ui->lineEdit->insert("2"); }

void MainWindow::on_pushButton_3_clicked() { ui->lineEdit->insert("3"); }

void MainWindow::on_pushButton_4_clicked() { ui->lineEdit->insert("4"); }

void MainWindow::on_pushButton_7_clicked() { ui->lineEdit->insert("7"); }

void MainWindow::on_pushButton_8_clicked() { ui->lineEdit->insert("8"); }

void MainWindow::on_pushButton_9_clicked() { ui->lineEdit->insert("9"); }

void MainWindow::on_pushButton_ln_clicked() { ui->lineEdit->insert("ln"); }

void MainWindow::on_pushButton_mod_clicked() { ui->lineEdit->insert("%"); }

void MainWindow::on_pushButton_sin_clicked() { ui->lineEdit->insert("sin"); }

void MainWindow::on_pushButton_cos_clicked() { ui->lineEdit->insert("cos"); }

void MainWindow::on_pushButton_tan_clicked() { ui->lineEdit->insert("tan"); }

void MainWindow::on_pushButton_acos_clicked() { ui->lineEdit->insert("acos"); }

void MainWindow::on_pushButton_atan_clicked() { ui->lineEdit->insert("atan"); }

void MainWindow::on_pushButton_sqrt_clicked() { ui->lineEdit->insert("sqrt"); }

void MainWindow::on_pushButton_left_bracket_clicked() {
  ui->lineEdit->insert("(");
}

void MainWindow::on_pushButton_right_bracket_clicked() {
  ui->lineEdit->insert(")");
}

void MainWindow::on_pushButton_plus_clicked() { ui->lineEdit->insert("+"); }

void MainWindow::on_pushButton_minus_clicked() { ui->lineEdit->insert("-"); }

void MainWindow::on_pushButton_mult_clicked() { ui->lineEdit->insert("*"); }

void MainWindow::on_pushButton_div_clicked() { ui->lineEdit->insert("/"); }

void MainWindow::on_pushButton_pow_clicked() { ui->lineEdit->insert("^"); }

void MainWindow::on_pushButton_again_clicked() { ui->lineEdit->clear(); }

void MainWindow::on_pushButton_plus_minus_clicked() {
  QString str = ui->lineEdit->text();
  int len = str.length();
  bool swapped = false;
  if (len > 0) {
    if (str[len - 1] == '-') {
      str[len - 1] = '+';
      swapped = true;
    } else if (str[len - 1] == '+') {
      str[len - 1] = '-';
      swapped = true;
    }
    if (!swapped) str += '-';
  } else {
    str = "";
  }
  ui->lineEdit->setText(str);
}

void MainWindow::on_pushButton_graph_clicked() {
  QString text = ui->lineEdit->text();
  char *val = text.toUtf8().data();
  int res = validator(val);
  if (res == 1) {
    ui->lineEdit->setText("ERROR");
  } else {
    char *expr_short = new char[strlen(val) + 1];
    change_string(val, expr_short, strlen(val));
    ui->widget->clearGraphs();
    double x_min_num = ui->d_f_1->value();
    double x_max_num = ui->d_f_2->value();
    double range_x = ui->e_f_1->value();
    double range_y = ui->e_f_2->value();

    xBegin = x_min_num;
    xEnd = x_max_num;

    ui->widget->xAxis->setRange(-1 * range_x, range_x);
    ui->widget->yAxis->setRange(-1 * range_y, range_y);

    h = 0.001;

    N = (xEnd - xBegin) / h + 2;

    for (X = xBegin; X < xEnd; X += h) {
      x.push_back(X);
      y.push_back(s21_calculate(expr_short, X));
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);

    ui->widget->setInteraction(QCP::iRangeZoom, true);
    ui->widget->setInteraction(QCP::iRangeDrag, true);

    ui->widget->replot();

    x.clear();
    y.clear();
  }
}

void MainWindow::on_pushButton_calculate_clicked() {
  QString text = ui->lineEdit->text();
  char *val = text.toUtf8().data();
  int res = validator(val);
  if (res == 2) {
    ui->lineEdit->setText("");
  } else if (res == 1) {
    ui->lineEdit->setText("ERROR");
  } else {
    char *expr_short = new char[strlen(val) + 1];
    change_string(val, expr_short, strlen(val));
    if (strchr(text.toUtf8().data(), 'x') != 0) {
      x1->show();
    } else {
      double result = s21_calculate(expr_short, 0);
      QString valueAsString = QString::number(result);
      ui->lineEdit->setText(valueAsString);
    }
  }
}

void MainWindow::update(QString txt) {
  QString text_val = ui->lineEdit->text();
  char *val = text_val.toUtf8().data();
  char *expr_short = new char[strlen(val) + 1];
  change_string(val, expr_short, strlen(val));
  double X = txt.toDouble();
  double result = s21_calculate(expr_short, X);
  QString valueAsString = QString::number(result);
  ui->lineEdit->setText(valueAsString);
}

void MainWindow::on_pushButton_x_clicked() { ui->lineEdit->insert("x"); }

void MainWindow::on_pushButton_0_clicked() { ui->lineEdit->insert("0"); }

void MainWindow::on_pushButton_point_clicked() { ui->lineEdit->insert("."); }
