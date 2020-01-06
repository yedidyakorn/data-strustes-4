#include "Graph.h"



bool Graph::addv(string str)
{
	if (myMap[str])
		return false;
	Vertex *temp = new Vertex(str);
	myMap[str] = temp;
	return true;
}

Graph::Graph()
{
}


Graph::~Graph()
{
}

Vertex::Vertex(string str)
{
	Key = str;
	list<Edge *> EdgeList;
}
