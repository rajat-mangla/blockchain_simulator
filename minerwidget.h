#ifndef MINERWIDGET_H
#define MINERWIDGET_H

#include <QWidget>
using namespace std;
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
    void displayCountryWidget(string country, int proportion);

private:
    Ui::minerWidget *ui;
};

#endif // MINERWIDGET_H
