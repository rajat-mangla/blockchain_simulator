#include "displaychain.h"
#include "ui_displaychain.h"
#include "blockWidget.h"
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

        blockWidget* customCard = new blockWidget;
        customCard->displayBlockWidget(list[i]);
        QListWidgetItem* tempItem = new QListWidgetItem();

        ui->blockList->addItem(tempItem);

        tempItem->setSizeHint(customCard->size());
        ui->blockList->setItemWidget(tempItem, customCard);
    }
}
