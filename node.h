#ifndef NODE
#define NODE
#include <vector>
using namespace std;

class Node{
private:
    static int totalNodes;
    int id;
    bool mining;
    int regionId;
    double downloadSpeed;
    double uploadSpeed;
    vector<int> connections;

public:
    Node(bool mining = 0);
    int getId();
    bool getMining();
    void setRegionId(int regionId);
    int getRegionId();
    void setDownloadSpeed(double downloadSpeed);
    double getDownloadSpeed();
    void setUploadSpeed(double uploadSpeed);
    double getUploadSpeed();
    vector<int> getConnections();
    void addConnection(int id);
};

#endif // NODE

