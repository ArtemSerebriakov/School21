#include "xdialog.h"

#include "ui_xdialog.h"

XDialog::XDialog(QWidget *parent) : QDialog(parent), ui(new Ui::XDialog) {
  ui->setupUi(this);
}

XDialog::~XDialog() { delete ui; }

void XDialog::on_pushButton_x_clicked() {
  QString text = ui->lineEdit_x->text();
  char *str = text.toUtf8().data();
  int res = 0;
  int i = 0;
  bool minus = 0;
  int length = strlen(str);
  if (length == 0) {
    res = 2;
  } else {
    while (*(str + i) != '\0') {
      char ch = *(str + i);
      if (((ch < 48) || (ch > 57)) && (ch != 45) && (ch != 46)) {
        res = 1;
      } else if (ch == 45) {
        if (i != 0) {
          res = 1;
        }
        minus = 1;
      } else if (ch == 46) {
        if (i == 0) {
          res = 1;
        }
        if ((minus == 1) && (i == 1)) {
          res = 1;
        }
      }
      i += 1;
    }
  }
  if ((res == 1) || (res == 2)) {
    ui->label_x->setText("Incorrect value!");
  } else {
    emit transmit(ui->lineEdit_x->text());
    ui->label_x->clear();
    hide();
  }
}
