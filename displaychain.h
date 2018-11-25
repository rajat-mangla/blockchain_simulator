#ifndef DISPLAYCHAIN_H
#define DISPLAYCHAIN_H

#include <QWidget>
#include <queue>
#include "block.h"
#include "region.h"
#include "node.h"
using namespace std;

namespace Ui {
class displayChain;
}

class displayChain : public QWidget
{
    Q_OBJECT

public:
    explicit displayChain(QWidget *parent = 0);
    ~displayChain();
    void displayBlockDetails(vector<Block> list);
    void displayMinerDetails(vector<Block> blockchain, vector<Region> regions, vector<Node> nodes);
    void displayStatistics(int staleBlocks, double simulationTime, double actualTime);

private:
    Ui::displayChain *ui;
};

#endif // DISPLAYCHAIN_H
