#ifndef BLOCKINFO_H
#define BLOCKINFO_H

#include <QWidget>
#include "block.h"

namespace Ui {
class blockWidget;
}

class blockWidget : public QWidget
{
    Q_OBJECT

public:
    explicit blockWidget(QWidget *parent = 0);
    ~blockWidget();
    void displayBlockWidget(Block block);

private:
    Ui::blockWidget *ui;
};

#endif // BLOCKINFO_H
