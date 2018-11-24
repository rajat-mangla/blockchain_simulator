#ifndef BLOCKINFO_H
#define BLOCKINFO_H

#include <QWidget>
#include "block.h"

namespace Ui {
class blockInfo;
}

class blockInfo : public QWidget
{
    Q_OBJECT

public:
    explicit blockInfo(QWidget *parent = 0);
    ~blockInfo();
    void displayBlockInfo(Block block);

private:
    Ui::blockInfo *ui;
};

#endif // BLOCKINFO_H
