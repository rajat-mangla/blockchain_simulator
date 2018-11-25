#include "block.h"
#include "transaction.cpp"

Block::Block(int id, int blockSize){
	this->id = id;
	this->blockSize = blockSize;
}

int Block::getId(){
	return this->id;
}

void Block::setMiner(int minerId){
	this->minerId = minerId;
}

int Block::getMinerId(){
	return this->minerId;
}

int Block::getBlockSize(){
	return this->blockSize;
}

void Block::setTimeCreated(double timeCreated){
	this->timeCreated = timeCreated;
}

double Block::getTimeCreated(){
	return this->timeCreated;
}

void Block::setTimeReceived(double timeReceived){
	this->timeReceived = timeReceived;
}

double Block::getTimeReceived(){
	return this->timeReceived;
}

void Block::addTransaction(Transaction transaction){
	this->transactions.push_back(transaction);
}

vector<Transaction> Block::getTransactions(){
	return this->transactions;
}
