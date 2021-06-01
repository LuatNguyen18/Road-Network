#pragma once
#include <iostream>
#include "Vertex.h"
using namespace std;

class Edge
{
private:
	//Data Member
	int weight;
	Vertex startv;
	Vertex endv;

public:
	//Constructor
	Edge();
	Edge(int, Vertex, Vertex);
	//Copy Constructor
	Edge (const Edge&);
	//Destructor
	~Edge();

	//Accessing Member Functions
	//Weight
	void setweight(int);
	int getweight() const;

	//Start Vertex
	void setstartv(Vertex);
	Vertex getstartv() const;

	//End Vertex
	void setendv(Vertex);
	Vertex getendv() const;

	//Operator Overloading
	bool operator==(const Edge& e);
};
