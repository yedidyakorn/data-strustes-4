#pragma once
#include <iostream>
#include<string>
#include<list>
#include<map>

using namespace std;

class Vertex;
class Edge
{
	double distination;
	Vertex* Start;
	Vertex* End;


public:
	Edge(Vertex*, Vertex*);
	~Edge();
	bool operator ==(Edge e) { return e.distination == this->distination; }
	string getEnd() { return End->key(); }
};


class Vertex
{
	string Key;
	list<Edge*>EdgeList;
	double d;
	double f;
	Vertex *pi;
public:
	Vertex(string);
	void addE(Edge*);
	bool distinationExsists();
	int numOfNeighbors();
	void print();
	string key() { return Key; }
	void removeEdges();


};




class Graph
{
	map <string, Vertex*> graph;

public:
	bool addv(string);
	bool adde(string,string);
	void printAll();
	void topologicalSort();
	Graph();
	~Graph();
};

