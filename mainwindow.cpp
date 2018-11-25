#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "simulator.cpp"
#include "displaychain.h"
#include "time.h"
#include <iostream>
using namespace std;

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
    clock_t tStart = clock();
    int numNodes = 100;
    int numMiners = 100;
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

    cout<<"\n Time taken: "<<(double)(clock() - tStart)/CLOCKS_PER_SEC <<"\n";
}
