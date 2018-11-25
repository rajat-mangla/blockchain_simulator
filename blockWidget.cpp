#include "blockWidget.h"
#include "ui_blockinfo.h"

blockWidget::blockWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::blockInfo)
{
    ui->setupUi(this);
}

blockWidget::~blockWidget()
{
    delete ui;
}

void blockWidget::displayBlockWidget(Block b){

    QString blockId = QString::fromStdString("Block Id: ");
    blockId.append(QString::number(b.getId()));

    QString blockTime = QString::fromStdString("Mined at: ");
    blockTime.append(QString::number(b.getTimeReceived()));

    QString minerId = QString::fromStdString("Mined by: ");
    minerId.append(QString::number(b.getMinerId()));

    ui->blockD->setText(blockId);
    ui->timeD->setText(blockTime);
    ui->mineD->setText(minerId);
}
