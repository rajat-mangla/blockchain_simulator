#include <vector>

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
    Node(bool mining = 0){
        this->id = totalNodes++;
        this->mining = mining;
    }

    int getId(){
        return this->id;
    }

    bool getMining(){
        return this->mining;
    }

    void setRegionId(int regionId){
        this->regionId = regionId;
    }

    int getRegionId(){
        return this->regionId;
    }

    void setDownloadSpeed(double downloadSpeed){
        this->downloadSpeed = downloadSpeed;
    }

    double getDownloadSpeed(){
        return this->downloadSpeed;
    }

    void setUploadSpeed(double uploadSpeed){
        this->uploadSpeed = uploadSpeed;
    }

    double getUploadSpeed(){
        return this->uploadSpeed;
    }

    vector<int> getConnections(){
        return this->connections;
    }

    void addConnection(int id){
        connections.push_back(id);
    }
};

int Node::totalNodes = 0;
