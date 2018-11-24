#include "simulator.cpp"

int main(){
	int numNodes = 10;
	int numMiners = 4;
	int numBlocks = 10;
	int blockSize = 1000;
	double blockInterval = 1;
	/*
	cout << "Number of Nodes : ";
	cin >> numNodes;
	cout << "Number of Miners : ";
	cin >> numMiners;
	cout << "Number of Blocks : ";
	cin >> numBlocks;
	cout << "Size of Block : ";
	cin >> blockSize;
	cout << "Block Interval : ";
	cin >> blockInterval;
	*/
	Simulator simulator(numNodes, numMiners, numBlocks, blockSize, blockInterval);
	simulator.run();
}
