#include "blockinfo.h"
#include "ui_blockinfo.h"

blockInfo::blockInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::blockInfo)
{
    ui->setupUi(this);
}

blockInfo::~blockInfo()
{
    delete ui;
}

void blockInfo::displayBlockInfo(Block b){

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
