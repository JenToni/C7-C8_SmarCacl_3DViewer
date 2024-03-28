#include "mainwindow.h"

#include <QKeyEvent>
#include <QMessageBox>
#include <QString>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->lineEdit_eq->clear();
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));

  connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_Open, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_Clouse, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(operations()));

  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(functions()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::digits_numbers()

{
  if (ui->lineEdit_eq->text().contains("Invalid Input"))
    ui->lineEdit_eq->setText("");
  QPushButton *button = (QPushButton *)sender();
  QString new_result = ui->lineEdit_eq->text() + button->text();
  ui->lineEdit_eq->setText(new_result);
}

void MainWindow::on_pushButton_dot_clicked() {
  if (ui->lineEdit_eq->text().contains("Invalid Input"))
    ui->lineEdit_eq->setText("");
  ui->lineEdit_eq->setText(ui->lineEdit_eq->text() + ".");
}

void MainWindow::operations() {
  if (ui->lineEdit_eq->text().contains("Invalid Input"))
    ui->lineEdit_eq->setText("");

  QPushButton *button = (QPushButton *)sender();
  QString new_result;
  new_result = ui->lineEdit_eq->text();

  if (button->text() == "÷" && !(ui->lineEdit_eq->text().endsWith("÷")) &&
      !(ui->lineEdit_eq->text().endsWith("/"))) {
    new_result += "/";
  } else if (button->text() == "*" &&
             !(ui->lineEdit_eq->text().endsWith("*"))) {
    new_result += "*";
  } else if (button->text() == "*" &&
             !(ui->lineEdit_eq->text().endsWith("*"))) {
    new_result += "*";
  } else if (button->text() == "+" &&
             !(ui->lineEdit_eq->text().endsWith("+"))) {
    new_result += "+";
  } else if (button->text() == "-" &&
             !(ui->lineEdit_eq->text().endsWith("-"))) {
    new_result += "-";
  } else if (button->text() == "pow" &&
             !(ui->lineEdit_eq->text().endsWith("pow"))) {
    new_result += "^";
  } else if (button->text() == "sqrt" &&
             !(ui->lineEdit_eq->text().endsWith("sqrt"))) {
    new_result += "sqrt(";
  } else if (button->text() == "mod" &&
             !(ui->lineEdit_eq->text().endsWith("mod"))) {
    new_result += "mod";
  } else if (button->text() == "(") {
    new_result += "(";
  } else if (button->text() == ")") {
    new_result += ")";
  } else if (button->text() == "x" &&
             !(ui->lineEdit_eq->text().endsWith("x"))) {
    new_result += "x";
  }
  ui->lineEdit_eq->setText(new_result);
}

void MainWindow::functions() {
  if (ui->lineEdit_eq->text().contains("Invalid Input"))
    ui->lineEdit_eq->setText("");
  QPushButton *button = (QPushButton *)sender();
  QString new_result;
  new_result = ui->lineEdit_eq->text() + button->text() + "(";
  ui->lineEdit_eq->setText(new_result);
}

void MainWindow::on_pushButton_AC_clicked() { ui->lineEdit_eq->setText(""); }

void MainWindow::on_pushButton_eq_clicked() {

  QByteArray ba = ui->lineEdit_eq->text().toLocal8Bit();

  char *input_str = ba.data();
  char str[256] = {0};
  int i = 0;
  for (; i < 255 && *input_str; i++) {
    str[i] = *input_str;
    input_str++;
  }
  str[i] = '\0';

  if (0 < i) {
    if (validate_str(str) == 0) {
      ui->lineEdit_eq->setText("Invalid Input");
    } else if (ui->lineEdit_eq->text().contains("x")) {
      double x = (ui->lineEdit->text()).toDouble();
      double answer = s21_calc(str, x);
      QString numberAnswer = QString::number(answer);
      ui->lineEdit_eq->setText(numberAnswer);
    } else {
      double answer = s21_calc(str, 0.0);
      QString numberAnswer = QString::number(answer);
      ui->lineEdit_eq->setText(numberAnswer);
    }
  } else
    ui->lineEdit_eq->setText("Invalid Input");
}

void MainWindow::on_pushButton_AC_2_clicked() {
  ui->lineEdit_eq->setText(
      ui->lineEdit_eq->text().left(ui->lineEdit_eq->text().size() - 1));
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
    on_pushButton_eq_clicked();
  }

  QMainWindow::keyPressEvent(event);
}


void MainWindow::on_graphic_clicked()
{
  graph.show();
}


void MainWindow::on_credit_clicked()
{
  credit.show();
}



