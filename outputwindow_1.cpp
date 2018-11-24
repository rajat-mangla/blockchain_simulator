#include "outputwindow_1.h"
#include "ui_outputwindow_1.h"

OutputWindow_1::OutputWindow_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OutputWindow_1)
{
    ui->setupUi(this);
}

OutputWindow_1::~OutputWindow_1()
{
    delete ui;
}
