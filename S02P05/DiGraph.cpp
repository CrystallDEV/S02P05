#include "stdafx.h"
#include <algorithm>
#include "DiGraph.h"
#include "SFMLGraphVisualizer.h"
#include <fstream>

/**
*
* @param key1
* @param key2
* @param weight
*/
void DiGraph::addEdge(string key1, string key2, float weight) {
	Edge *edge = new Edge(getNodeByKey(key1), getNodeByKey(key2), weight);
	getNodeByKey(key1)->setNewEdge(edge);
}

/**
*
* @param node
*/
void DiGraph::addNode(Node *node) {
	this->nodes.append(node);
}

/**
*
* @param key1
* @param x
* @param y
*/
void DiGraph::addNode(string key, int x, int y) {
	this->nodes.append(new Node(key, x, y));
}

/**
*
* @param key
* @return
*/
Liste<Edge *> DiGraph::getEdges(string key) {
	return getNodeByKey(key)->getEdges();
}

/**
*
* @param key
* @return
*/
Liste<Node *> DiGraph::getNeighbours(string key) {
	Liste<Node *> nodes = this->getNodes();
	Liste<Node *> neighbours = NULL;
	for (int pos = 0; pos < nodes._last; pos++) {
		if (nodes._values[pos]->node_key == key) {
			if (neighbours.contains(nodes._values[pos])) continue;
			neighbours.append(nodes._values[pos]);
		}
	}

	return neighbours;
}

/**
*
* @return
*/
Liste<Node *> DiGraph::getNodes() {
	return this->nodes;
}

/**
*
* @param key
* @return
*/
Node *DiGraph::getNodeByKey(string key) {
	Liste<Node *> nodes = this->getNodes();
	for (int pos = 0; pos < nodes._last; pos++) {
		if (nodes._values[pos]->node_key == key) {
			return nodes._values[pos];
		}
	}
	return NULL;
}

void DiGraph::loadFromFile() {
	ifstream nodesFile("nodes.txt");
	ifstream edgesFile("edges.txt");
	
	try {
		string a;
		int b, c;
		cout << "Nodes: " << endl;
		while (nodesFile >> a >> b >> c)
		{
			cout << a << " " << b << " " << c << " " << endl;
			addNode(a, b, c);
		}
		cout << " " << endl;
		
		string e1, e2;
		int e3;
		cout << "Edges: " << endl;
		while (edgesFile >> e1 >> e2 >> e3)
		{
			cout << e1 << " " << e2 << " " << e3 << " " << endl;
			addEdge(e1, e2, e3);
		}
		edgesFile.close();
	}catch (const exception& e) {
		cout << e.what() << endl;
	}
}

void DiGraph::saveToFile() {
	ofstream nodesFile("nodes.txt");
	ofstream edgesFile("edges.txt");

	try {
		nodesFile.clear();
		edgesFile.clear();

		string a;
		int b, c;
		for(int i = 0; i< nodes.size(); i++){
			Node *node = nodes[i];
			nodesFile << node->node_key << " " << node->positionX << " " << node->positionY << " " << endl;
		}
		nodesFile.close();

		string e1, e2;
		int e3;
		for (int i = 0; i < nodes.size(); i++) {
			{
				Liste<Edge*> edges = nodes[i]->edges;
				for (int x = 0; x < edges.size(); x++) {
					Edge *edge = edges[x];
					edgesFile << edge->getStartNode()->node_key <<  " " << edge->getEndNode()->node_key << " " << edge->getWeight() << endl;;
				}
			}
		}
		edgesFile.close();

	}catch (const exception& e) {
		cout << e.what() << endl;
	}
}