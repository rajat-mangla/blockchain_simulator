#include <vector>
#include "node.h"

Node::Node(bool mining){
    this->id = totalNodes++;
    this->mining = mining;
}

int Node::getId(){
    return this->id;
}

bool Node::getMining(){
    return this->mining;
}

void Node::setRegionId(int regionId){
    this->regionId = regionId;
}

int Node::getRegionId(){
    return this->regionId;
}

void Node::setDownloadSpeed(double downloadSpeed){
    this->downloadSpeed = downloadSpeed;
}

double Node::getDownloadSpeed(){
    return this->downloadSpeed;
}

void Node::setUploadSpeed(double uploadSpeed){
    this->uploadSpeed = uploadSpeed;
}

double Node::getUploadSpeed(){
    return this->uploadSpeed;
}

vector<int> Node::getConnections(){
    return this->connections;
}

void Node::addConnection(int id){
    connections.push_back(id);
}

int Node::totalNodes = 0;
