#pragma once

#include "Liste.h"
#include "Node.h"

using namespace std;

class DiGraph {
private:
	Liste<Node *> nodes;
	Node * getNodeByKey(string key);

public:
	void addNode(Node *node);
	void addNode(std::string key, int x, int y);
	void addEdge(string key1, string key2, float weight);
	Liste<Node *> getNeighbours(string key);
	Liste<Edge *> getEdges(string key);
	Liste<Node *> getNodes();
	void loadFromFile();
	void saveToFile();
};

