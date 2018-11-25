#ifndef TRANSACTION
#define TRANSACTION
#include <iostream>
using namespace std;

class Transaction{
private:
    string from, to;
    int amount;
public:
    Transaction(string from = "", string to = "", int amount = 0);
    void setFrom(string from);
    string getFrom();
    void setTo(string to);
    string getTo();
    void setAmount(int amount);
    int getAmount();
};

#endif // TRANSACTION

