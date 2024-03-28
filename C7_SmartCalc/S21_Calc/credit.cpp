#include "credit.h"
#include "ui_credit.h"

Credit::Credit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Credit)
{
    ui->setupUi(this);
}

Credit::~Credit()
{
    delete ui;
}


void Credit::on_calc_clicked()
{
    bool ok;
    // если передали не дабл то значение = 0
    double summ = QString(ui->summ->text()).toDouble(&ok);
    int month = QString(ui->month->text()).toInt(&ok);
    double percent = QString(ui->percent->text()).toDouble(&ok);
    ui->tableWidget->setRowCount(month);
    percent /=1200;
    if (ui->ann->isChecked()){
        double month_pay = (summ * percent)/(1 - powf(1 + percent,-month));
        double total = month_pay * month;
        double over_pay = total - summ;
        double sum = summ;
        ui->overpayment->setText(QString::number(over_pay, 'f',2));
        ui->total->setText(QString::number(total,'f',2));
        for (int i = 0; i < month; i++)
        {

            ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(month_pay, 'f',2)));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(sum * percent, 'f',2)));
            sum -= (month_pay - (sum * percent));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(sum, 'f',2)));
        }

    }
    if (ui->dif->isChecked()){
        double month_pay = 0;
        double remainder,p_debt;
        double main_debt = summ / month;
        double total = 0;
        for (int i = 0; i < month; i++)
        {
            remainder = summ-(main_debt * i);
            p_debt = remainder * percent;
            month_pay = p_debt + main_debt;
            total += month_pay;
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(month_pay, 'f',2)));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(p_debt, 'f',2)));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(remainder - main_debt, 'f',2)));
        }
        ui->overpayment->setText(QString::number(total - summ, 'f',2));
        ui->total->setText(QString::number(total,'f',2));
    }

}


void Credit::on_clear_clicked()
{
    ui->tableWidget->clear();
    ui->overpayment->clear();
    ui->total->clear();
    ui->summ->clear();
    ui->month->clear();
    ui->percent->clear();
}

