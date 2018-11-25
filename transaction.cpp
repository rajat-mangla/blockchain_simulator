#include "transaction.h"

Transaction::Transaction(string from, string to, int amount){
	this->from = from;
	this->to = to;
	this->amount = amount;
}

void Transaction::Transaction::setFrom(string from){
	this->from = from;
}

string Transaction::getFrom(){
	return this->from;
}

void Transaction::setTo(string to){
	this->to = to;
}

string Transaction::Transaction::getTo(){
	return this->to;
}

void Transaction::setAmount(int amount){
	this->amount = amount;
}

int Transaction::getAmount(){
	return this->amount;
}
