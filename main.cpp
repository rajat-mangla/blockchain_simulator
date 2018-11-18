#include "simulator.cpp"

int main(){
	int numNodes = 100;
	int numMiners = 10;
	int numBlocks = 1000;
	int blockSize = 10;
	double blockInterval = 10;
	/*cout << "Number of Nodes : ";
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
