#include "transactiondisplay.h"
#include "ui_transactiondisplay.h"

transactionDisplay::transactionDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::transactionDisplay)
{
    ui->setupUi(this);
    ui->listWidget->setStyleSheet( "QListWidget::item { border-bottom: 1px solid black; }" );
}

transactionDisplay::~transactionDisplay()
{
    delete ui;
}

void transactionDisplay::display(vector<Block> blockchain){
    int numNodes = blockchain.size();
    for (int i=0; i< numNodes; i++){
        Block b = blockchain[i];


        QString blockId = QString::fromStdString("Block Id: ");
        blockId.append(QString::number(b.getId()));


        QListWidgetItem *item = new QListWidgetItem();

        //item->setData(Qt::DisplayRole, blockId);
        item->setTextAlignment(Qt::AlignCenter);


        vector<Transaction> tempTransaction = b.getTransactions();
        for (int j=0; j< tempTransaction.size(); j++){
            Transaction temp = tempTransaction[j];

            //QString transactionString = QString::fromStdString(temp.getFrom());

            blockId.append(QString::fromStdString("\n"));

            blockId.append(QString::fromStdString(temp.getFrom()));
            blockId.append(QString::fromStdString(" gives amount "));
            blockId.append(QString::number(temp.getAmount()));
            blockId.append(QString::fromStdString(" to "));
            blockId.append(QString::fromStdString(temp.getTo()));
            //transactionString.append(QString::fromStdString(temp.getTo()));
            //transactionString.append(QString::number(temp.getAmount()));

            //item->setData(Qt::UserRole, transactionString);
        }

        item->setText(blockId);
        ui->listWidget->addItem(item);
    }
}
