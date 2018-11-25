class Region{
private:
	static int totalRegions;
    int id;
    string name;
    double maxDownloadSpeed;
    double maxUploadSpeed;
    int nodeProportion;
    int minerProportion;
    int computationPower;

public:
	Region(string name = "", double maxDownloadSpeed = 0.0, double maxUploadSpeed = 0.0, int nodeProportion = 0, int minerProportion = 0){
		this->id = totalRegions++;
		this->name = name;
		this->maxDownloadSpeed = maxDownloadSpeed;
		this->maxUploadSpeed = maxUploadSpeed;
		this->nodeProportion = nodeProportion;
		this->minerProportion = minerProportion;
		this->computationPower = minerProportion*100+100;
	}

	int getId(){
		return this->id;
	}

	string getName(){
		return this->name;
	}

	double getMaxDownloadSpeed(){
		return this->maxDownloadSpeed;
	}

	double getMaxUploadSpeed(){
		return this->maxUploadSpeed;
	}

	int getNodeProportion(){
		return this->nodeProportion;
	}

	int getMinerProportion(){
		return this->minerProportion;
	}

	int getComputationPower(){
		return this->computationPower;
	}
};

int Region::totalRegions = 0;
