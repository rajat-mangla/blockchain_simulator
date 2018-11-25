#include "displaychain.h"
#include "ui_displaychain.h"
#include "blockWidget.h"
#include "minerwidget.h"
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

void displayChain::displayBlockDetails(vector<Block> list){
    for (int i=0;i<list.size();i++){

        blockWidget* customWidget = new blockWidget;
        customWidget->displayBlockWidget(list[i]);
        QListWidgetItem* tempItem = new QListWidgetItem();

        ui->blockList->addItem(tempItem);

        tempItem->setSizeHint(customWidget->size());
        ui->blockList->setItemWidget(tempItem, customWidget);
    }
}

void displayChain::displayMinerDetails(vector<Block> blockchain){
    map<int, int> miners;
    int numNodes = blockchain.size();
    for (int i=0; i< numNodes; i++){
        Block b = blockchain[i];
        if (miners.find(b.getMinerId()) == miners.end()){
            miners[b.getMinerId()]=1;
        }else{
            miners[b.getMinerId()]++;
        }
    }

    map<int,int>::iterator it;
    for (it=miners.begin(); it!=miners.end(); it++){

        int proportion = (it->second)*100;
        proportion = proportion/numNodes;

        minerWidget *customWidget = new minerWidget;
        customWidget->displayWidget(it->first, proportion);

        QListWidgetItem* tempItem = new QListWidgetItem();

        ui->minersListWidget->addItem(tempItem);

        tempItem->setSizeHint(customWidget->size());
        ui->minersListWidget->setItemWidget(tempItem, customWidget);
    }

}
