#pragma once

#include "Liste.h"
#include "Edge.h"
#include <cstdlib>
#include <string>

using namespace std;

class Node {
public:
	string node_key;
	int positionX;
	int positionY;
	Liste<Edge *> edges;

	Node(string key, int positionX, int positionY);

	string getKey(void);

	int getPositionX(void);

	int getPositionY(void);

	Liste<Edge *> getEdges(void);

	void setKey(string new_key);

	void setPositionX(int x);

	void setPositionY(int y);

	void setNewEdge(Edge *edge);

};
