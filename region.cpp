#include "region.h"

Region::Region(string name, double maxDownloadSpeed, double maxUploadSpeed, int nodeProportion, int minerProportion){
    this->id = totalRegions++;
    this->name = name;
    this->maxDownloadSpeed = maxDownloadSpeed;
    this->maxUploadSpeed = maxUploadSpeed;
    this->nodeProportion = nodeProportion;
    this->minerProportion = minerProportion;
    this->computationPower = minerProportion*100+100;
}

int Region::getId(){
    return this->id;
}

string Region::getName(){
    return this->name;
}

double Region::getMaxDownloadSpeed(){
    return this->maxDownloadSpeed;
}

double Region::getMaxUploadSpeed(){
    return this->maxUploadSpeed;
}

int Region::getNodeProportion(){
    return this->nodeProportion;
}

int Region::getMinerProportion(){
    return this->minerProportion;
}

int Region::getComputationPower(){
    return this->computationPower;
}

int Region::totalRegions = 0;
