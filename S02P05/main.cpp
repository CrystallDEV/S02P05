// S02P03_new.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

#include "DiGraph.h"
#include "SFMLGraphVisualizer.h"

int main() {
	DiGraph g;
	g.loadFromFile();
/*
	g.addNode("A", 40, 80);
	g.addNode("E", 400, 40);
	g.addNode("D", 600, 200);
	g.addNode("F", 240, 240);
	g.addNode("C", 280, 500);
	g.addNode("B", 120, 440);

	g.addEdge("A", "E", 10);
	g.addEdge("D", "E", 3);
	g.addEdge("C", "D", 9);
	g.addEdge("F", "D", 2);
	g.addEdge("B", "C", 7);
	g.addEdge("B", "F", 1);
	g.addEdge("A", "B", 5);
	g.addEdge("F", "A", 7);
	*/
	g.saveToFile();
	SFMLGraphVisualizer sgv;
	sgv.visualize(g);
}