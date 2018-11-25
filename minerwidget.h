#ifndef MINERWIDGET_H
#define MINERWIDGET_H

#include <QWidget>

namespace Ui {
class minerWidget;
}

class minerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit minerWidget(QWidget *parent = 0);
    ~minerWidget();
    void displayWidget(int minerId, int proportion);

private:
    Ui::minerWidget *ui;
};

#endif // MINERWIDGET_H
