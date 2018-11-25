#include "minerwidget.h"
#include "ui_minerwidget.h"

minerWidget::minerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::minerWidget)
{
    ui->setupUi(this);
}

minerWidget::~minerWidget()
{
    delete ui;
}

void minerWidget::displayWidget(int minerId, int proportion){

    QString minerIdS = QString::fromStdString("Miner Id: ");
    minerIdS.append(QString::number(minerId));

    ui->minerD->setText(minerIdS);
    ui->progressBar->setValue(proportion);
}

void minerWidget::displayCountryWidget(string country, int proportion){

    QString minerIdS = QString::fromStdString("Country : ");
    minerIdS.append(QString::fromStdString(country));

    ui->minerD->setText(minerIdS);
    ui->progressBar->setValue(proportion);
}
