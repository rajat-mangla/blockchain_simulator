#ifndef DISPLAYCHAIN_H
#define DISPLAYCHAIN_H

#include <QWidget>
#include <queue>
#include "block.h"

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
    void displayList(vector<Block> list);

private:
    Ui::displayChain *ui;
};

#endif // DISPLAYCHAIN_H
