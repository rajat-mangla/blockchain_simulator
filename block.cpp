#include "block.h"

Block::Block(int parentId, int minerId, int blockSize, double timeCreated){
    this->id = totalBlocks++;
    this->parentId = parentId;
    this->minerId = minerId;
    this->blockSize = blockSize;
    this->timeCreated = timeCreated;
}

int Block::getId(){
    return this->id;
}

int Block::getParentId(){
    return this->parentId;
}

int Block::getMinerId(){
    return this->minerId;
}

int Block::getBlockSize(){
    return this->blockSize;
}

double Block::getTimeCreated(){
    return this->timeCreated;
}

void Block::setTimeCreated(double timeCreated){
    this->timeCreated = timeCreated;
}

double Block::getTimeReceived(){
    return this->timeReceived;
}

void Block::setTimeReceived(double timeReceived){
    this->timeReceived = timeReceived;
}

int Block::totalBlocks = 0;
