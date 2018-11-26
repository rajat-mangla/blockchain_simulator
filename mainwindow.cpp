#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "simulator.cpp"
#include "displaychain.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->numBlocks->setValidator(new QIntValidator(1,10000,this));
    ui->numNodes->setValidator(new QIntValidator(1,10000,this));
    ui->numMiners->setValidator(new QIntValidator(1,10000,this));
    ui->blockSize->setValidator(new QIntValidator(1,32,this));
    ui->blockInterval->setValidator(new QDoubleValidator(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Simulate_clicked()
{
    int numNodes = 100;
    int numMiners = 100;
    int numBlocks = 100;
    int blockSize = 8;   // in Mbits/sec
    double blockInterval = 10; // in sec

    numNodes = ui->numNodes->text().toInt();

    numMiners = ui->numMiners->text().toInt();

    numBlocks = ui->numBlocks->text().toInt();

    blockSize = ui->blockSize->text().toInt();

    blockInterval = ui->blockInterval->text().toDouble();

    if ((numNodes > 0 && numMiners > 0 && numBlocks > 0 && blockSize > 0 && blockInterval > 0) &&
            numMiners <= numNodes){

        ui->errorLabel->setText("<font color='green'>Blockchain Simulation</font>");

        Simulator simulator(numNodes, numMiners, numBlocks, blockSize, blockInterval);
        //this->close();
        simulator.run();
    }
    else{
        ui->errorLabel->setText("<font color='red'>Please provide correct inputs</font>");
    }
}
