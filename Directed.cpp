#include "Directed.h"



//Constructor
Directed::Directed() :Graph()
{
	//Initialise Data Value
	nbvertex = 0;
	nbedge = 0;

}

//Constructor with arguments
Directed::Directed(Edge& e1, Vertex& v1, Vertex& v2)
{
	//Attributing data members
	vertexlist[0] = v1;
	vertexlist[1] = v2;
	nbvertex = 2;

	edgelist[0] = e1;
	nbedge = 1;

}

//Copy constructor
Directed::Directed(const Directed& und)
{
	//Setting up variables
	nbvertex = und.nbvertex;
	nbedge = und.nbedge;
	vertexlist = und.vertexlist;
	edgelist = und.edgelist;
}



//Destructor
Directed::~Directed()
{
	cout << "Directed Destructor Called" << endl;
}

//Accessing member functions
int Directed::getnbvertex()
{
	return nbvertex;
}

int Directed::getnbedge()
{
	return nbedge;
}



//Prints weights
void Directed::printweight()
{
	//Prints start of message
	cout << "Value of weight of edges in graph:" << edgelist[0].getweight();

	//Loops for the rest of the weights
	for (int i = 1; i < nbedge; i++)
	{
		cout << "," << edgelist[i].getweight();
	}
	cout << endl;
}


//Function to check if graph is empty
bool Directed::empty()
{
	if (!vertexlist.empty())
		return false; //Returns false if its not empty
	else
		return true; //returns true if empty
}




//add in one vertex or multiple; bool returns if it is added successfully.
bool Directed::addVertex(Vertex& v)
{
	//Push back the vertex into the list and increments nbvertex
	vertexlist.push_back(v);
	nbvertex++;
	return true;
}

//Add multiple vertices
bool Directed::addVertices(Vertex* vArray, int size)
{

	for (int i = 0; i < size; i++)
	{
		vertexlist.push_back(vArray[i]);
		nbvertex++;
	}

	return true;

}

//Remove a vertex
bool Directed::removeVertex(Vertex& v)
{
	for (int t = 0; t < nbvertex; t++)
	{
		//Search for the vertex
		if (vertexlist[t] == v)
		{
			//Removing edges that contain this vertex
			for (int i = 0; i < nbedge; i++)	//Loops through to search 
			{
				if ((edgelist[i].getstartv().getid() == vertexlist[t].getid()) || (edgelist[i].getendv().getid() == vertexlist[t].getid()))	//Checks starting and ending id
				{
					edgelist.erase(edgelist.begin() + i);	//removes object
					nbedge--;
				}
			}

			vertexlist.erase(vertexlist.begin() + t);	//Removes object
			nbvertex--;	//Deincrement


		}
	}
	return true;
}

//Addedge
bool Directed::addEdge(Edge& e)
{
	//Adds e and increments list
	edgelist.push_back(e);
	nbedge++;
	return true;
}

//Adds multiples edges
bool Directed::addEdges(Edge* obj, int a)
{
	for (int i = 0; i < a; i++)
	{
		//Adds the vertices contained in a dynamic array to the vector
		edgelist.push_back(obj[i]);
		nbedge++;
	}

	return true;
}


//Removes edge
bool Directed::removeEdge(Edge& e)
{
	for (int i = 0; i < nbedge; i++)
	{
		//Searches for e
		if (edgelist[i] == e)
		{
			edgelist.erase(edgelist.begin() + i);	//removes object
			nbedge--;
		}
	}
	return true;
}

//Search Functions
// return bool if a vertex exists in a graph;
bool Directed::searchVertex(const Vertex& v)
{
	for (int i = 0; i < nbvertex; i++)
	{
		if (vertexlist[i] == v)
		{
			return true;	//Returns true if v is in the vertex list
		}
	}

	return false;
}

// return bool if a Edge exists in a graph;
bool Directed::searchEdge(const Edge& e)
{
	for (int i = 0; i < nbedge; i++)
	{
		if (edgelist[i] == e)		//Loops through to search 
		{
			return true;			//Returns true if its in the vector
		}
	}

	return false;
}


//Searches for vertex with value and prints vertex id
void Directed::searchvertexvalue(int a)
{
	bool found = false;
	int index = 0;

	for (int i = 0; i < vertexlist.size(); i++)
	{
		if (vertexlist[i].getvalue() == a)
		{
			found = true;
			index = i;
			break;
		}
	}

	if (found)
	{
		cout << "ID of vertex with a value of " << a << ": " << vertexlist[index].getid() << endl;
	}

	else
		cout << "There are no vertex with that value in the graph." << endl;
}

//Checks in graph if theres a vertex with same starting and ending vertex id
bool Directed::searchedge(int start, int end)
{
	for (int i = 0; i < nbedge; i++)	//Loops through to search 
	{
		if ((edgelist[i].getstartv().getid() == start) && (edgelist[i].getendv().getid() == end))	//Checks starting and ending id
		{
			return true;			//Returns true if its in the graph
		}
	}
	return false;
}





// display the whole graph with your own defined format
void Directed::display()
{
	//Displaying Graph
	cout << "Graph: " << endl;

	//Displaying Vertex In graph
	//If vectorlist is empty do not display
	if (!vertexlist.empty())
	{
		cout << "V = {" << vertexlist.at(0).getid();	//prints first element if size isnt 0
		for (int i = 1; i < nbvertex; i++)				//Loops to print the rest with comma in front
			cout << "," << vertexlist.at(i).getid();
		cout << "}" << endl;
	}
	else
		cout << "No vertices in graph." << endl;	//if the vector is empty


	//Displaying Edge in Graph
	//If edgelist is empty
	if (!edgelist.empty())
	{
		cout << "E = {" << "(" << edgelist.at(0).getstartv().getid() << "," << edgelist.at(0).getendv().getid() << ")";	//Same logic than for vertex list
		for (int i = 1; i < nbedge; i++)
			cout << ",(" << edgelist.at(i).getstartv().getid() << "," << edgelist.at(i).getendv().getid() << ")";
		cout << "}" << endl;
	}
	else
		cout << "No edges in graph." << endl;	//if the vector is empty
}


// define your own format of a string representation of the graph.
string Directed::toString()
{
	//Message String begining
	string message;
	message = "E = {(";

	//If there is no edge
	if (edgelist.empty())
		return "There is no edges in this graph.";

	//First edge
	message.append(to_string(edgelist.at(0).getstartv().getvalue()));
	message.append(",");
	message.append(to_string(edgelist.at(0).getendv().getvalue()));

	//Adds all the following edges to message string
	for (int i = 1; i < nbedge; i++)
	{
		message.append(", (");
		message.append(to_string(edgelist.at(i).getstartv().getvalue()));
		message.append(",");
		message.append(to_string(edgelist.at(i).getendv().getvalue()));
		message.append(")");

	}

	//The end of the message
	message.append("}");

	return message;
}


//remove all the vertices and edges
bool Directed::clean()
{
	//Clears content leaving the vector with size 0
	vertexlist.clear();
	edgelist.clear();

	return true;
}





// Prints all paths from a vertex s to a vertex d
void Directed::printAllPaths(int s, int d)
{

	// Create an array to store paths
	int* path = new int[vertexlist.size() + 1];
	int path_index = 0; // Initialize path[] as empty

	//Stores if visited
	vector<bool> visited;	//Dirty bits

	//Pushback into vector all to false
	for (int i = 0; i < vertexlist.size() + 1; i++)		//One for each vertex
		visited.push_back(0);

	// Call the recursive helper function to print all paths
	printpaths(s, d, visited, path, path_index);
}


//Recursive function to prints paths
void Directed::printpaths(int u, int d, vector<bool> visited, int path[], int& path_index)
{

	// Mark the current node and store it in path[]
	visited[u] = 1;
	path[path_index] = u;
	path_index++;	//increment index

	// If current vertex is same as destination, then print
	// current path[]
	if (u == d) 
	{
		for (int i = 0; i < path_index; i++)
			cout << path[i] << " ";
		cout << endl;
	}



	else // If current vertex is not destination
	{
		// Recur for all the vertices adjacent to current vertex
		for (int i = 0; i < edgelist.size(); i++)
		{
			//Checks if edge has starting vertex equal this vertex
			if (edgelist[i].getstartv().getid() == u)
			{
				//Checks if it has been visited
				if (!visited[edgelist[i].getendv().getid()])
					//Calls function recursively
					printpaths(edgelist[i].getendv().getid(), d, visited, path, path_index);
			}

		}
	}

	//Unmarked from visited and decrement so the recursive functions can come back where it left
	visited[u] = 0;
	path_index--;
}





//Print all possible paths
void Directed::printAP()
{
	//Creates all permutations of the vertices and print paths
	for (int i = 1; i <= vertexlist.size(); i++)
	{
		for (int n = 1; n <= vertexlist.size(); n++)
		{
			printAllPaths(i, n);
		}
	}
}


//Print all possible paths with queried starting vertex
void Directed::printlead(int vertex1)
{
	//Creates all permutation with starting vertex vertex1
	for (int n = 1; n <= vertexlist.size(); n++)
	{
		printAllPaths(vertex1, n);
	}

}






//Operator Overloading
//returns true if G1 and G2 have the exact same vertices and edges
bool Directed::operator==(const Directed& und)
{
	//checks if it has same amount of vertices and edges
	if ((nbvertex != und.nbvertex) || (nbedge != und.nbedge))
		return false;

	//Checking to see all vertex are the same
	for (int i = 0; i < nbvertex; i++)
	{
		if (vertexlist[i] == und.vertexlist[i])
			break;
		else
			return false;
	}

	return true;
}



//G1 = G2, assign Graph G2 to Graph G1
void Directed::operator=(const Directed& g2)
{
	//Copying variables
	nbvertex = g2.nbvertex;
	nbedge = g2.nbedge;
	vertexlist = g2.vertexlist;
	edgelist = g2.edgelist;

}

//Increases weight of all edges by one
void Directed::operator++()
{
	for (unsigned int i = 0; i < edgelist.size(); i++)	//Loops through all elements
	{
		edgelist.at(i).setweight(edgelist.at(i).getweight() + 1);	//Adds 1 to current weight
	}
}




//returns a graph that contains all the nodes of G1 and G2, all the edges of G1 and G2
Directed Directed::operator+(const Directed& g)
{
	Directed und;

	//Adding all edges from g1
	for (unsigned int i = 0; i < edgelist.size(); i++)
	{
		und.addEdge(edgelist[i]);
	}

	//Adding all edges from g2
	for (unsigned int i = 0; i < g.edgelist.size(); i++)
	{
		und.edgelist.push_back(g.edgelist[i]);
		und.nbedge++;
	}

	//Adding all vertices from g1
	for (unsigned int i = 0; i < vertexlist.size(); i++)
	{
		und.addVertex(vertexlist[i]);
	}

	//Adding all vertices from g2
	for (unsigned int i = 0; i < g.vertexlist.size(); i++)
	{
		und.vertexlist.push_back(g.vertexlist[i]);
		und.nbvertex++;
	}

	//Returns a graph with g1 and g2 together
	return und;
}


//Returns boolean if the sum of weights of G1’ edges are larger than the sum of weights of G2’s edges
bool Directed::operator>(const Directed& g2)
{
	//Initialise at 0
	int weight1 = 0;
	int weight2 = 0;

	for (unsigned int i = 0; i < edgelist.size(); i++)	//Loops through all elements for g1
	{
		weight1 += edgelist[i].getweight();		//Adds weight of each edge to current value of weight1
	}

	for (unsigned int i = 0; i < g2.edgelist.size(); i++)	//Loops through all elements for g2
	{
		weight2 += g2.edgelist[i].getweight();		//Adds weight of each edge to current value of weight1
	}

	//Checks which is bigger
	if (weight1 > weight2)
		return true;
	else
		return false;

}


//outputs the graph und
ostream& operator<<(ostream& output, const Directed& und)
{
	//Displaying Graph
	output << "Graph: " << endl;

	//Displaying Vertex In graph
	//If vectorlist is empty do not display
	if (!und.vertexlist.empty())
	{
		output << "V = {" << und.vertexlist.at(0).getvalue();	//first element if size isnt 0
		for (int i = 1; i < und.nbvertex; i++)				//Loops to print the rest with comma in front
			output << "," << und.vertexlist[i].getvalue();
		output << "}" << endl;
	}
	else
		output << "No vertices in graph." << endl;	//if the vector is empty


	//Displaying Edge in Graph
	//If edgelist is empty
	if (!und.edgelist.empty())
	{
		output << "E = {" << "(" << und.edgelist.at(0).getstartv().getvalue() << "," << und.edgelist.at(0).getendv().getvalue() << ")";	//Same logic than for vertex list
		for (int i = 1; i < und.nbedge; i++)
			output << ",(" << und.edgelist.at(i).getstartv().getvalue() << "," << und.edgelist.at(i).getendv().getvalue() << ")";
		output << "}" << endl;
	}
	else
		output << "No edges in graph." << endl;	//if the vector is empty

	//Enables cout of the information from the graph
	return output;
}