#include "graph.h"

#include <QKeyEvent>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_graph.h"

// #include <QDoubleValidator>
// #include <QRegularExpression>

Graph::Graph(QWidget* parent) : QWidget(parent), ui(new Ui::Graph) {
    ui->setupUi(this);
    ui->X_min->setText("-100");
    ui->X_max->setText("100");
    ui->X_range->setText("100");
    ui->Y_range->setText("100");
}

Graph::~Graph() { delete ui; }

void Graph::on_pushButton_clicked() {
    ui->widget->clearGraphs();

    bool ok;
    // если передали не дабл то значение = 0
    double x_min = QString(ui->X_min->text()).toDouble(&ok);
    double x_max = QString(ui->X_max->text()).toDouble(&ok);
    double x_range = QString(ui->X_range->text()).toDouble(&ok);
    double y_range = QString(ui->Y_range->text()).toDouble(&ok);

    if (x_range > 1000000) x_range = 1000000;
    if (y_range > 1000000) y_range = 1000000;
    if (x_min < -1000000) x_min = -1000000;
    if (x_max > 1000000) x_max = 1000000;

    QByteArray ba = ui->Form->text().toLocal8Bit();
    char* input_str = ba.data();
    char str[256] = {0};
    int i = 0;

    for (; i < 255 && *input_str; i++) {
        str[i] = *input_str;
        input_str++;
    }
    str[i] = '\0';

    if (x_max > x_min && validate_str(str) == 1) {
        ui->widget->xAxis->setRange(-1 * x_range, x_range);
        ui->widget->yAxis->setRange(-1 * y_range, y_range);

        if (ui->point->isChecked())
            h = 0.01;
        else
            h = 0.1;

        xBegin = x_min;
        xEnd = x_max;

        for (X = xBegin; X < xEnd; X += h) {
            x.push_back(X);
            y.push_back(s21_calc(str, X));
        }

        ui->widget->addGraph();
        ui->widget->graph(0)->addData(x, y);

        // переключение на точки
        if (ui->point->isChecked()) {
            ui->widget->graph(0)->setPen(QColor(50, 50, 50, 255));
            ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
            ui->widget->graph(0)->setScatterStyle(
                QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
        }
        // зум и сдвиг
        ui->widget->setInteraction(QCP::iRangeZoom, true);
        ui->widget->setInteraction(QCP::iRangeDrag, true);

        ui->widget->replot();

        x.clear();
        y.clear();

    }

    else
        ui->Form->setText("Invalid Input");
}
