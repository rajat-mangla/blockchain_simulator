#ifndef OUTPUTWINDOW_1_H
#define OUTPUTWINDOW_1_H

#include <QDialog>

namespace Ui {
class OutputWindow_1;
}

class OutputWindow_1 : public QDialog
{
    Q_OBJECT

public:
    explicit OutputWindow_1(QWidget *parent = 0);
    ~OutputWindow_1();

private:
    Ui::OutputWindow_1 *ui;
};

#endif // OUTPUTWINDOW_1_H
