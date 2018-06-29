#include "stdafx.h"
#include "Edge.h"

Edge::Edge(Node *startNode, Node *endNode, float weight) {
	this->startNode = startNode;
	this->endNode = endNode;
	this->weight = weight;
}

Node *Edge::getEndNode() {
	return this->endNode;
}

Node *Edge::getStartNode() {
	return this->startNode;
}

float Edge::getWeight() {
	return this->weight;
}

void Edge::setEndNode(Node *n) {
	this->endNode = n;
}

void Edge::setStartNode(Node *n) {
	this->startNode = n;
}

void Edge::setWeight(float w) {
	this->weight = w;
}