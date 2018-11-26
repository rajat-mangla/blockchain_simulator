#include "mainwindow.h"
#include <QApplication>
#include "displaychain.h"
#include "transactiondisplay.h"
using namespace std;

displayChain* chainList;
transactionDisplay* transactionList;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    chainList = new displayChain();
    transactionList = new transactionDisplay();

    w.show();
    return a.exec();
}

void displayListInfo(vector<Block> list, vector<Region> regions, vector<Node> nodes){
  chainList->show();
  chainList->displayBlockDetails(list);
  chainList->displayMinerDetails(list, regions, nodes);
}

void displayOtherInfo(int numStaleBlocks, double simulationTime, double actualTime){
    chainList->displayStatistics(numStaleBlocks,simulationTime, actualTime);
}

void displayTransactionListInfo(vector<Block> list){
  transactionList->show();
  transactionList->display(list);
}
