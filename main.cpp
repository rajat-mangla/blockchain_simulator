#include "mainwindow.h"
#include <QApplication>
#include "displaychain.h"
using namespace std;

displayChain* chainList;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    chainList = new displayChain();

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
