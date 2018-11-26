#ifndef TRANSACTIONDISPLAY_H
#define TRANSACTIONDISPLAY_H

#include <QWidget>
#include "block.h"
using namespace std;

namespace Ui {
class transactionDisplay;
}

class transactionDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit transactionDisplay(QWidget *parent = 0);
    ~transactionDisplay();
    void display(vector<Block> blockchain);
private:
    Ui::transactionDisplay *ui;
};

#endif // TRANSACTIONDISPLAY_H
