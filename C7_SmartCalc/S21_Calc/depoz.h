#ifndef DEPOZ_H
#define DEPOZ_H

#include <QWidget>
#include <QDate>

namespace Ui {
class Depoz;
}

class Depoz : public QWidget
{
    Q_OBJECT

public:
    explicit Depoz(QWidget *parent = nullptr);
    ~Depoz();

private slots:
    void on_pushButton_eq_clicked();
    void calculate();

private:
    Ui::Depoz *ui;
    QDate dt;
    double calculateInterest(double amount, double interestRate, int capitalizationPeriod, int durationMonths);
    double calculateTax(double interest, double taxRate);
};

#endif // DEPOZ_H
