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
        tempItem->setTextAlignment(Qt::AlignCenter);
        ui->blockList->setItemWidget(tempItem, customWidget);
    }
}

void displayChain::displayMinerDetails(vector<Block> blockchain, vector<Region> regions, vector<Node> nodes){
    map<int, int> miners;
    map<string, int> countries;
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

        countries[regions[nodes[it->first].getRegionId()].getName()]+= proportion;

        minerWidget *customWidget = new minerWidget;
        customWidget->displayWidget(it->first, proportion);

        QListWidgetItem* tempItem = new QListWidgetItem();

        ui->minersListWidget->addItem(tempItem);

        tempItem->setSizeHint(customWidget->size());
        ui->minersListWidget->setItemWidget(tempItem, customWidget);
    }

    map<string,int>::iterator it2;
    for (it2=countries.begin(); it2!=countries.end(); it2++){

        minerWidget *customWidget = new minerWidget;
        customWidget->displayCountryWidget(it2->first, it2->second);

        QListWidgetItem* tempItem = new QListWidgetItem();

        ui->regionListWidget->addItem(tempItem);

        tempItem->setSizeHint(customWidget->size());
        ui->regionListWidget->setItemWidget(tempItem, customWidget);
    }
}

void displayChain::displayStatistics(int staleBlocks, double simulationTime, double actualTime){
    ui->statisticsWidget->setColumnCount(2);
    ui->statisticsWidget->setColumnWidth(0,(this->width()*2)/3);
    ui->statisticsWidget->setColumnWidth(1,this->width()/3);

    ui->statisticsWidget->setRowCount(3);

    ui->statisticsWidget->setItem(0,0,new QTableWidgetItem("No. of Stale Blocks"));
    ui->statisticsWidget->setItem(0,1,new QTableWidgetItem(QString::number(staleBlocks)));

    ui->statisticsWidget->setItem(1,0,new QTableWidgetItem("Time taken to Simulate Blockchain"));
    QString tempString = QString::number(simulationTime);
    tempString.append(" Sec");
    ui->statisticsWidget->setItem(1,1,new QTableWidgetItem(tempString));

    ui->statisticsWidget->setItem(2,0,new QTableWidgetItem("Actual Time taken to build Blockchain"));
    tempString = QString::number(actualTime/60);
    tempString.append(" Min");
    ui->statisticsWidget->setItem(2,1,new QTableWidgetItem(tempString));
}
