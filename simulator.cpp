#include "data.cpp"
#include "node.cpp"
#include "region.cpp"
#include <iostream>
#include <queue>
#include <map>
#include <stdlib.h>
#include <iomanip>
#include "displaychain.h"
#include "main.h"

using namespace std;

class myComparator{
public:
    int operator()(Block b1, Block b2){
        return b1.getTimeReceived() > b2.getTimeReceived();
    }
};

class Simulator{
private:
	int numNodes;
	int numMiners;
	int numBlocks;
	int blockSize;
	double blockInterval;
	vector<Node> nodes;
	vector<Region> regions;
	vector<Block> blockchain;
	vector<Block> staleBlocks;

public:
	Simulator(int numNodes = 0, int numMiners = 0, int numBlocks = 0, int blockSize = 1, double blockInterval = 1.0){
		this->numNodes = numNodes;
		this->numMiners = numMiners;
		this->numBlocks = numBlocks;
		this->blockSize = blockSize;
		this->blockInterval = blockInterval;
		initRegions();
		initNodes();
		blockchain.clear();
		staleBlocks.clear();
	}

	void initRegions(){
		for(int i = 0; i < NUM_REGIONS; i++){
			regions.push_back(Region(regionNames[i], regionDownloadSpeeds[i], regionUploadSpeeds[i], nodeProportion[i], minerProportion[i]));
		}
	}

	void initNodes(){
		srand(time(NULL));
		assignRegions();
		assignSpeeds();
		makeConnections();
	}

	void assignRegions(){
		for(int i = 0; i < numNodes-numMiners; i++){
			int j = 0;
			int k = rand()%100;
			int sum = 0;
			for(j = 0; j < NUM_REGIONS; j++){
				sum += regions[j].getNodeProportion();
				if(sum >= k){
					break;
				}
			}
			Node n(0);
			n.setRegionId(j);
			nodes.push_back(n);
		}
		
		for(int i = 0; i < numMiners; i++){
			int j = 0;
			int k = rand()%100;
			int sum = 0;
			for(j = 0; j < NUM_REGIONS; j++){
				sum += regions[j].getMinerProportion();
				if(sum >= k){
					break;
				}
			}
			Node n(1);
			n.setRegionId(j);
			nodes.push_back(n);
		}
	}

	void assignSpeeds(){
		for(int i = 0; i < nodes.size(); i++){
			double maxDownloadSpeed = regions[nodes[i].getRegionId()].getMaxDownloadSpeed();
			double maxUploadSpeed = regions[nodes[i].getRegionId()].getMaxUploadSpeed();
			double extra = maxDownloadSpeed - (int) maxDownloadSpeed;
			nodes[i].setDownloadSpeed((rand()%(int) maxDownloadSpeed) + extra);
			extra = maxUploadSpeed - (int) maxUploadSpeed;
			nodes[i].setUploadSpeed((rand()%(int) maxUploadSpeed) + extra);
		}
	}

	void makeConnections(){
		int root = rand()%numNodes;

		for(int i = 0; i < numNodes; i++){
			if(i != root){
				nodes[root].addConnection(i);
				nodes[i].addConnection(root);
			}
		}

		for(int i = 0; i < numNodes; i++){
			for(int j = i+1; j < numNodes; j++){
				if(i != root && j != root){
					if(rand()%2){
						nodes[j].addConnection(i);
						nodes[i].addConnection(j);
					}
				}
			}
		}
	}

	void run(){
		vector< priority_queue<Block, vector<Block>, myComparator> > pq(numNodes);
		int numValidatedNodes;
		double time = 0.0;
		for(int i = 0; i < numBlocks; i++){
			pair<int, int> miner = calculateMiner();
			int currBlockSize = 1+rand()%blockSize;
			time += currBlockSize/nodes[miner.first].getDownloadSpeed();
			time += calculateMiningTime(miner.second);
			vector<int> validatedNodes(numNodes, 0);
			validatedNodes[miner.first] = 1;
			numValidatedNodes = 1;
			Block b(i-1, miner.first, currBlockSize, time);
			b.setTimeReceived(time);
			pq[miner.first].push(b);
			broadcast(pq, miner.first, validatedNodes, numValidatedNodes, b);
			time = max(time, (i+1)*blockInterval);
		}

        /*for(int i = 0; i < numNodes; i++){
			showpq(pq[i]);
        }*/

		int cnt = numNodes*numBlocks;
		while(cnt > 0){
			vector< pair<int, int> > blocks;
			map<int, int> mp;
			int blockId = -1, maxOccurence = -1;
			for(int j = 0; j < numNodes; j++){
				if(pq[j].empty()){
					continue;
				}
				Block b = pq[j].top();
				mp[b.getId()]++;
				if(maxOccurence < mp[b.getId()]){
					maxOccurence = mp[b.getId()];
					blockId = b.getId();
				}
				blocks.push_back(make_pair(b.getId(), b.getTimeReceived()));
			}
			int maxTime = -1;
			for(int j = 0; j < blocks.size(); j++){
				if(blocks[j].first == blockId && maxTime < blocks[j].second){
					maxTime = blocks[j].second;
				}
			}
			for(int j = 0; j < numNodes; j++){
				if(!pq[j].empty()){
					Block b = pq[j].top();
					if(b.getId() == blockId && !inBlockchain(b) && !isStale(b)){
						blockchain.push_back(b);
						break;
					}
				}
			}
			for(int j = 0; j < numNodes; j++){
				if(pq[j].empty()){
					continue;
				}
				Block b = pq[j].top();
				if(isStale(b) || inBlockchain(b)){
					pq[j].pop();
					cnt--;
					continue;
				}
				if(b.getTimeReceived() <= maxTime){
					pq[j].pop();
					cnt--;
					if(b.getMinerId() == j){
						staleBlocks.push_back(b);
					}
				}
			}
		}
        displayList(blockchain);
        /*
		cout << "\nBlockchain: " << "\n";
		for(int i = 0; i < blockchain.size(); i++){
			cout << blockchain[i].getId() << " " << blockchain[i].getMinerId() << "\n";
		}

		cout << "\nStale Blocks: " << "\n";
		for(int i = 0; i < staleBlocks.size(); i++){
			cout << staleBlocks[i].getId() << " " << staleBlocks[i].getMinerId() << "\n";
		}
		*/
		cout << "\n# of blocks in main chain: " << blockchain.size() << "\n";
		cout << "\n# of stale blocks: " << staleBlocks.size() << "\n";

	}

	bool broadcast(vector< priority_queue<Block, vector<Block>, myComparator> > &pq, int senderId, vector<int> &validatedNodes, int numValidatedNodes, Block block){
		if(numNodes == numValidatedNodes){
			return true;
		}

		double time = block.getTimeReceived() + block.getBlockSize()/nodes[senderId].getUploadSpeed();

		vector<int> connections = nodes[senderId].getConnections();
		vector<int> validationTimeOfNodes;
		for(int i = 0; i < connections.size(); i++){
			if(validatedNodes[connections[i]] == 0){
				validatedNodes[connections[i]] = 1;
				double t = time + block.getBlockSize()/nodes[connections[i]].getDownloadSpeed();
				block.setTimeReceived(t);
				validationTimeOfNodes.push_back(t);
				pq[connections[i]].push(block);
				numValidatedNodes++;
			}
			else{
				validationTimeOfNodes.push_back(-1);
			}
			if(numNodes == numValidatedNodes){
				return true;
			}
		}

		for(int i = 0; i < connections.size(); i++){
			if(validationTimeOfNodes[i] != -1){
				block.setTimeReceived(validationTimeOfNodes[i]);
				if(broadcast(pq, connections[i], validatedNodes, numValidatedNodes, block)){
					return true;
				}
			}
		}
		return false;
	}

	pair<int, int> calculateMiner(){
		int maxx = -1, ind = -1;
		for(int i = 0; i < nodes.size(); i++){
			if(nodes[i].getMining()){
				int j = 1+rand()%regions[nodes[i].getRegionId()].getComputationPower();
				if(j > maxx){
					maxx = j;
					ind = i;
				}
			}
		}
		return make_pair(ind, maxx);
	}

	double calculateMiningTime(int power){
		return 1.0/power;
	}

	void showpq(priority_queue<Block, vector<Block>, myComparator> pq){
        vector<Block> temp;
        while(!pq.empty()){
	    	Block b = pq.top();
	    	pq.pop();
            temp.push_back(b);
            //cout << setw(10) << b.getTimeReceived() << "(" << b.getId() << ")";
	    }
        displayList(temp);
        //cout << '\n';
	}

	bool isStale(Block b){
		for(int i = 0; i < staleBlocks.size(); i++){
			if(b.getId() == staleBlocks[i].getId()){
				return true;
			}
		}
		return false;
	}

	bool inBlockchain(Block b){
		for(int i = 0; i < blockchain.size(); i++){
			if(b.getId() == blockchain[i].getId()){
				return true;
			}
		}
		return false;
	}
};
