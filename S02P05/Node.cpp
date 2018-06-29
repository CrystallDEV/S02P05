//
// Created by Marek on 25.05.2018.
//
#include "stdafx.h"
#include "Node.h"

/**
*
* @param key
* @param positionX
* @param positionY
* @param edges
*/
Node::Node(string key, int positionX, int positionY) {
	this->node_key = key;
	this->positionX = positionX;
	this->positionY = positionY;
}

/**
*
* @return
*/
string Node::getKey(void) {
	return this->node_key;
}

/**
*
* @return
*/
int Node::getPositionX(void) {
	return this->positionX;
}

/**
*
* @return
*/
int Node::getPositionY(void) {
	return this->positionY;
}

/**
*
* @return
*/
Liste<Edge *> Node::getEdges(void) {
	return this->edges;
}

/**
*
* @param new_key
*/
void Node::setKey(string new_key) {
	this->node_key = new_key;
}

/**
*
* @param x
*/
void Node::setPositionX(int x) {
	this->positionX = x;
}

/**
*
* @param y
*/
void Node::setPositionY(int y) {
	this->positionY = y;
}

/**
*
* @param edge
*/
void Node::setNewEdge(Edge *edge) {
	this->edges.append(edge);
}