#ifndef BLOCK
#define BLOCK

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
    Block(int parentId, int minerId, int blockSize, double timeCreated);
    int getId();
    int getParentId();
    int getMinerId();
    int getBlockSize();
    double getTimeCreated();
    void setTimeCreated(double timeCreated);
    double getTimeReceived();
    void setTimeReceived(double timeReceived);
};

#endif // BLOCK

