#pragma once
#include "Graph.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Undirected : public Graph
{
private:
	//Data members
	vector<Vertex> vertexlist;
	int nbvertex;

	vector<Edge> edgelist;
	int nbedge;


	//Recursive function used to print paths
	void printpaths(int, int, vector<bool>, int[], int&);

public:
	//Constructor
	Undirected();
	Undirected(Edge&, Vertex&, Vertex&);
	//Copy Constructor
	Undirected(const Undirected&);
	//Destructor
	virtual ~Undirected();

	//Accessing member functions
	int getnbvertex();
	int getnbedge();

	//Weight print function
	virtual void printweight();



	//Checks if graph is empty
	virtual bool empty();



	//add in one vertex or multiple; bool returns if it is added successfully.
	virtual bool addVertex(Vertex& );
	virtual bool addVertices(Vertex*, int);	//Add multiple through dynamic array
	virtual bool removeVertex(Vertex&);	//the edges that has connection with this vertex need to be removed;
	virtual bool addEdge(Edge&);
	virtual bool addEdges(Edge*, int);
	virtual bool removeEdge(Edge&);	// remove the edge

	//Search Functions
	// return bool if a vertex exists in a graph;
	virtual bool searchVertex(const Vertex& v);
	// return bool if a Edge exists in a graph;
	virtual bool searchEdge(const Edge& e);
	//Queries vertex value and couts id of vertex
	virtual void searchvertexvalue(int);
	//Queries starting vertex and ending vertex and returns bool
	virtual bool searchedge(int,int);
	


	// display the whole graph with your own defined format
	virtual void display();
	
	// define your own format of a string representation of the graph.
	virtual string toString();

	//remove all the vertices and edges;
	virtual bool clean();



	//A graph can be displayed by listing all the possible paths, each linking vertices. 
	virtual void printAllPaths(int,int);	//Printing all paths between two vertex
	virtual void printAP();					//Print all linking vertices paths
	virtual void printlead(int);				//Print all paths with leading vertex queried
	

	//Operator Overloading
	bool operator==(const Undirected &);
	void operator=(const Undirected &);
	void operator++();
	Undirected operator+(const Undirected &);
	bool operator>(const Undirected &);
	friend ostream& operator<<(ostream&, const Undirected&);
};

