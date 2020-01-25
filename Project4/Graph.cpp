/*
File: Graph.cpp
Description: clases of the graph and its Ingredients
Course: Data structres
Exercise 4
Author: Yedidya Korn-203304084 & David Abelo-208764340
*/
#include "Graph.h"


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
	if (!(this->checkVal(a))|| !(this->checkVal(b)) ||graph[a]->checkTarget(graph[b]))
		return false;
	Edge *temp = new Edge(graph[a], graph[b]);
	graph[a]->addE(temp);
	return true;
}

void Graph::printAll()
{
	for ( map <string, Vertex*>::iterator it = graph.begin(); it != graph.end(); ++it)
	{
		(*it).second->print();
		cout << endl;
	}
}

void Graph::subTopologicalSort(string str,  stack<string>& st)
{
	graph[str]->check =true;
	for (list<Edge*>::iterator it = graph[str]->EdgeList.begin(); it != graph[str]->EdgeList.end(); ++it)
		if ((*it)->End->check==false)
			subTopologicalSort((*it)->End->key(), st);
	st.push(str);
}

void Graph::topologicalSort()
{
	stack<string> st;
	for (map <string, Vertex*>::iterator it = graph.begin(); it != graph.end(); ++it)
		(*it).second->check = false;
	for (map <string, Vertex*>::iterator it = graph.begin(); it != graph.end(); ++it)
		if ((*it).second->check == false)
			subTopologicalSort((*it).first, st);
	cout << "order: ";
	while (st.empty() == false) {
		cout << st.top() << " ";
		st.pop();
	}
}

bool Graph::checkVal(string str)
{
	for (map <string, Vertex*>::iterator it = graph.begin(); it != graph.end(); ++it)
		if ((*it).first == str)
			return true;
	return false;
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
}

void Vertex::addE(Edge* edge)
{
	EdgeList.push_back(edge);
}

void Vertex::print()
{
	cout << Key << ": ";
	for (list<Edge*>::iterator it = EdgeList.begin(); it != EdgeList.end(); ++it)
		cout << (*it)->End->key()<<" ";
}

bool Vertex::checkTarget(Vertex * a)
{
	for (list<Edge*>::iterator it = EdgeList.begin(); it != EdgeList.end(); ++it)
		if ((*it)->End == a)
			return true;
	return false;
}

Edge::Edge(Vertex* start, Vertex* end)
{
	Start = start;
	End = end;
}
