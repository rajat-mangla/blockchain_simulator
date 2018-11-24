#include "displaychain.h"
#include "ui_displaychain.h"
using namespace std;

displayChain::displayChain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::displayChain)
{
    ui->setupUi(this);
}

displayChain::~displayChain()
{
    delete ui;
}

void displayChain::displayList(vector<Block> list){
    for (int i=0;i<list.size();i++){
        Block b = list[i];
        QString temp = QString::number(b.getTimeReceived());
        temp.append('(');
        temp.append(QString::number(b.getId()));
        temp.append(')');
        QListWidgetItem* newItem = new QListWidgetItem;
        newItem->setText(temp);
        ui->blockList->addItem(newItem);
    }
}
