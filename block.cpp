#include "transaction.cpp"
#include <vector>

class Block{
private:
	int id;
	int minerId;
	int blockSize;
	double timeCreated;
	double timeReceived;
	vector<Transaction> transactions;

public:
	Block(int id, int blockSize){
		this->id = id;
		this->blockSize = blockSize;
	}

	int getId(){
		return this->id;
	}

	void setMiner(int minerId){
		this->minerId = minerId;
	}

	int getMinerId(){
		return this->minerId;
	}

	int getBlockSize(){
		return this->blockSize;
	}

	void setTimeCreated(double timeCreated){
		this->timeCreated = timeCreated;
	}

	double getTimeCreated(){
		return this->timeCreated;
	}

	void setTimeReceived(double timeReceived){
		this->timeReceived = timeReceived;
	}

	double getTimeReceived(){
		return this->timeReceived;
	}

	void addTransaction(Transaction transaction){
		this->transactions.push_back(transaction);
	}

	vector<Transaction> getTransactions(){
		return this->transactions;
	}
};
