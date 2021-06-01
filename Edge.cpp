#include "Edge.h"


//Constructor
Edge::Edge()
{
	weight = 0;
}

//Constructor with arguments

Edge::Edge(int a, Vertex start, Vertex end)
{
	weight = a;
	startv = start;
	endv = end;
}

//Copy Constructor
Edge::Edge(const Edge& edge1)
{
	weight = edge1.weight;
	startv = edge1.startv;
	endv = edge1.endv;
}

//Destructor
Edge::~Edge()
{
}

//Accessing Member Functions
//Weight
void Edge::setweight(int a)
{
	weight = a;
}
int Edge::getweight() const
{
	return weight;
}

//Start Vertex
void Edge:: setstartv(Vertex start)
{
	startv = start;
}

Vertex Edge :: getstartv() const
{
	return startv;
}

//End Vertex
void Edge::setendv(Vertex end)
{
	endv = end;
}

Vertex Edge::getendv() const
{
	return endv;
}

//Operator Overloading
bool Edge::operator==(const Edge& e)
{
	//Checks if all data members are the same
	if ((weight == e.weight) && (startv == e.startv) && (endv == e.endv))
		return true;
	else
		return false;
}