#pragma once
#include "Edge.h"
#include "Vertex.h"
#include <iostream>
#include <string>
using namespace std;

class Graph
{
public:
	//Constructor
	Graph();
	virtual ~Graph();

	//add in one vertex; bool returns if it is added successfully.
	virtual bool addVertex(Vertex& v) = 0;
	virtual bool addVertices(Vertex* vArray, int) = 0;

	//the edges that has connection with this vertex need to be removed;
	virtual bool removeVertex(Vertex&) = 0;
	//remove a edge;  as a result, some node may remain as orphan.
	virtual bool addEdge(Edge& e) = 0;

	virtual bool addEdges(Edge*, int)=0;

	// remove the edge
	virtual bool removeEdge(Edge& e) = 0;
	// return bool if a vertex exists in a graph;
	virtual bool searchVertex(const Vertex& v) = 0;
	
	// return bool if a Edge exists in a graph;
	virtual bool searchEdge(const Edge & e) = 0;

	//Weight print function
	virtual void printweight()=0;

	//Checks if graph is empty
	virtual bool empty()=0;

	//Queries vertex value and couts id of vertex
	virtual void searchvertexvalue(int) = 0;
	//Queries starting vertex and ending vertex and returns bool
	virtual bool searchedge(int, int) =0;

	// display the whole graph with your own defined format
	virtual void display() = 0;
	// convert the whole graph to a string such as 1‐2‐4‐5; 1‐3‐5; each path is separated by ';'
	

	// define your own format of a string representation of the graph.
	virtual string toString() = 0;


	//remove all the vertices and edges;
	virtual bool clean() = 0;
	

	//A graph can be displayed by listing all the possible paths, each linking vertices. 
	virtual void printAllPaths(int, int)=0;	//Printing all paths between two vertex
	virtual void printAP()=0;					//Print all linking vertices paths
	virtual void printlead(int)=0;				//Print all paths with leading vertex queried

};

