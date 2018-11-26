#ifndef MAIN
#define MAIN
#include <vector>
#include "block.h"
#include "region.h"
#include "node.h"

void displayListInfo(vector<Block> list, vector<Region> regions, vector<Node> nodes);

void displayOtherInfo(int numStaleBlocks, double simulationTime, double actualTime);

void displayTransactionListInfo(vector<Block> list);

#endif // MAIN

