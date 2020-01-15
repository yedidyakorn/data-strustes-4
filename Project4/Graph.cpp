#include "Graph.h"

//???? ??? ???? ?? ???????? ?????
//???? ????? ?? ?? ????????? ???? DFS

bool Graph::addv(string str)
{
	if (graph[str])
		return false;
	Vertex *temp = new Vertex(str);
	graph[str] = temp;
	return true;
}

bool Graph::adde(string a, string b)
{
	if (!graph[a]||!graph[b])
		return false;
	Edge *temp = new Edge(graph[a], graph[b]);
	graph[a]->addE(temp);
	return true;
}

void Graph::printAll()
{
	for (auto it = graph.begin(); it != graph.end(); ++it)
	{
		(*it).second->print();
		cout << endl;
	}
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
	list<Edge*> EdgeList;
}

void Vertex::addE(Edge* edge)
{
	EdgeList.push_back(edge);
}

void Vertex::print()
{
	cout << Key << ": ";
	for (auto it = EdgeList.begin(); it != EdgeList.end(); ++it)
		cout << (*it)->getEnd()<<" ";
}

Edge::Edge(Vertex* start, Vertex* end)
{
	Start = start;
	End = end;
}
