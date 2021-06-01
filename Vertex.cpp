#include "Vertex.h"

//Initialising id
int Vertex :: nextid = 1;

//Constructor
Vertex :: Vertex()
{
	id = nextid;
	nextid++;
	value = 0;
	
	
}

Vertex :: Vertex(int a)
{
	id = nextid;
	nextid++;
	value = a;
}

//Copy Constructor
Vertex :: Vertex(const Vertex& vertex1)
{
	id = vertex1.id;
	value = vertex1.value;
}

//Destructor
Vertex:: ~Vertex()
{
}

//Accessing Member Function
//ID
int Vertex::getid() const
{
	return id;
}

//Value
int Vertex::getvalue() const
{
	return value;
}

void Vertex::setvalue(int a)
{
	value = a;
}

//Operator Overloading
bool Vertex::operator==(const Vertex& v)
{
	if ((id == v.id) && (value == v.value))	//Checks if all data members are the same
		return true;
	else
		return false;
}