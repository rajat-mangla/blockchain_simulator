class Transaction{
private:
	string from, to;
	int amount;

public:
	Transaction(string from = "", string to = "", int amount = 0){
		this->from = from;
		this->to = to;
		this->amount = amount;
	}

	void setFrom(string from){
		this->from = from;
	}

	string getFrom(){
		return this->from;
	}

	void setTo(string to){
		this->to = to;
	}

	string getTo(){
		return this->to;
	}

	void setAmount(int amount){
		this->amount = amount;
	}

	int getAmount(){
		return this->amount;
	}
};
