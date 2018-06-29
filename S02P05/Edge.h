#pragma once

class Node;

class Edge {
private:
	Node * startNode;
	Node *endNode;
	float weight;

public:
	Edge(Node *startNode, Node *endNode, float weight);

	float getWeight();

	Node *getStartNode(void);

	Node *getEndNode(void);

	void setWeight(float w);

	void setStartNode(Node *n);

	void setEndNode(Node *n);
};

