class Block{
private:
	static int totalBlocks;
	int id;
	int parentId;
	int minerId;
	int blockSize;
	double timeCreated;
	double timeReceived;

public:
	Block(int parentId, int minerId, int blockSize, double timeCreated){
		this->id = totalBlocks++;
		this->parentId = parentId;
		this->minerId = minerId;
		this->blockSize = blockSize;
		this->timeCreated = timeCreated;
	}

	int getId(){
		return this->id;
	}

	int getParentId(){
		return this->parentId;
	}

	int getMinerId(){
		return this->minerId;
	}

	int getBlockSize(){
		return this->blockSize;
	}

	double getTimeCreated(){
		return this->timeCreated;
	}

	void setTimeCreated(double timeCreated){
		this->timeCreated = timeCreated;
	}

	double getTimeReceived(){
		return this->timeReceived;
	}

	void setTimeReceived(double timeReceived){
		this->timeReceived = timeReceived;
	}
};

int Block::totalBlocks = 0;
