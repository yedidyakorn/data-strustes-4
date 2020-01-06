#pragma once
#include <iostream>
#include<string>
#include<list>
#include<map>

using namespace std;

class Vertex;
class Edge
{
public:
	double distination;
	Vertex* start;
	Vertex* end;
	Edge();
	~Edge();
	bool operator ==(Edge e) { return e.distination == this->distination; }
};

class Vertex
{
	string Key;
	list<Edge *>EdgeList;
	double d;
	double f;
	Vertex *pi;
public:
	Vertex(string);
	void addE(Edge);
	bool distinationExsists();
	int numOfNeighbors();
	void print();
	void removeEdges();


};




class Graph
{

public:
	map <string, Vertex*> myMap;
	bool addv(string);
	bool adde(string,string);
	void printAll();
	void topologicalSort();
	Graph();
	~Graph();
};

