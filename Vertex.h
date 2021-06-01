#pragma once
#include <iostream>
using namespace std;

class Vertex
{
private:
	//Data Member
	int id;
	static int nextid;
	int value;

public:
	//Constructor
	Vertex();
	Vertex(int);
	//Copy Constructor
	Vertex(const Vertex &);
	//Destructor
	~Vertex();

	//Accessing Member Function
	//ID
	int getid() const;

	//Value
	int getvalue() const;
	void setvalue(int);

	//Operator Overloading
	bool operator==(const Vertex& v);
};

