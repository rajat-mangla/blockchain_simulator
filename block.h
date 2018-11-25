#ifndef BLOCK
#define BLOCK
#include <vector>
#include "transaction.h"

class Block{
private:
    int id;
    int minerId;
    int blockSize;
    double timeCreated;
    double timeReceived;
    vector<Transaction> transactions;
public:
    Block(int id, int blockSize);
    int getId();
    void setMiner(int minerId);
    int getMinerId();
    int getBlockSize();
    double getTimeCreated();
    void setTimeCreated(double timeCreated);
    double getTimeReceived();
    void setTimeReceived(double timeReceived);
    void addTransaction(Transaction transaction);
    vector<Transaction> getTransactions();
};

#endif // BLOCK

