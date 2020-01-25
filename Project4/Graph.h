/*
File: Graph.h
Description: clases of the graph and its Ingredients
Course: Data structres
Exercise 4
Author: Yedidya Korn-203304084 & David Abelo-208764340
*/
#pragma once
#include <iostream>
#include<string>
#include<list>
#include<map>
#include <stack>
#include <iterator>

using namespace std;

class Vertex;
class Edge
{

public:
	Vertex* Start;
	Vertex* End;
	Edge(Vertex*, Vertex*);
	~Edge();
};


class Vertex
{
	string Key;
public:
	Vertex(string);
	list<Edge*> EdgeList;
	bool check;		// an paremetr used when graph searching (DFS)
	void addE(Edge*);		//add Edge
	void print();
	string key() { return Key; }
	bool checkTarget(Vertex*);		//checks if points to a spesific Vertex
};


class Graph
{
	map <string, Vertex*> graph;
	void subTopologicalSort(string str, stack<string>& st);		// recursive functaion  for DFS
	bool checkVal(string);		//checks if a string is a key in the map

public:
	bool addv(string);		//adds Vertex to graph
	bool adde(string,string);		//adds Edge to graph
	void printAll();
	void topologicalSort();
	Graph();
	~Graph();
};