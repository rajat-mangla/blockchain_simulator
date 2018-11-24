#ifndef REGION
#define REGION

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
    Region(string name = "", double maxDownloadSpeed = 0.0, double maxUploadSpeed = 0.0, int nodeProportion = 0, int minerProportion = 0);
    int getId();
    string getName();
    double getMaxDownloadSpeed();
    double getMaxUploadSpeed();
    int getNodeProportion();
    int getMinerProportion();
    int getComputationPower();
};

#endif // REGION

