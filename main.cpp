#include "mainwindow.h"
#include <QApplication>
#include "displaychain.h"
using namespace std;

displayChain* chainList;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

void displayList(vector<Block> list, vector<Region> regions, vector<Node> nodes){
  chainList = new displayChain();
  chainList->show();
  chainList->displayBlockDetails(list);
  chainList->displayMinerDetails(list, regions, nodes);
}
