#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "simulator.cpp"
#include "displaychain.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Simulate_clicked()
{
    int numNodes = 10;
    int numMiners = 4;
    int numBlocks = 100;
    int blockSize = 100;
    double blockInterval = 10;

    /*numNodes = ui->numNodes->text().toInt();

    numMiners = ui->numMiners->text().toInt();

    numBlocks = ui->numBlocks->text().toInt();

    blockSize = ui->blockSize->text().toInt();
*/
    Simulator simulator(numNodes, numMiners, numBlocks, blockSize, blockInterval);
    this->close();
    simulator.run();
}
