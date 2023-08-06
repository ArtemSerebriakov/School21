#include <unistd.h>

#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QMovie>
#include <QPushButton>
#include <QString>
#include <QWidget>
#include <iostream>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.setWindowTitle("Calculator");
  w.show();
  return a.exec();
}
