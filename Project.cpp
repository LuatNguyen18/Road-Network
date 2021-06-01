// Project.cpp 
//Justin Goi 40171109
//Luat Dinh Nguyen 40174891

#include <iostream>
#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"
#include "Undirected.h"
#include "Directed.h"
using namespace std;

int main()
{

	//Welcoming user to program
	cout << "Welcome to our project tester!" << endl;


	//Testing function 1 and 2
	cout << "\nTesting function 1 and 2." << endl;
	cout << "An empty graph of type directed and one of type undirected has been initialized." << endl;
	//Undirected
	cout << "The undirected graph displays: " << endl;
	Undirected und1;
	und1.display();

	//Directed
	cout << "The directed graph displays: " << endl;
	Directed directed1;
	directed1.display();


	//Testing function 3
	cout << "\nTesting function 3 and 4." << endl;

	try
	{
		//Prompt number of vertex
		cout << "To test function three please enter the number of vertex you wish to create: ";
		int nbvertex;
		cin >> nbvertex;

		if (nbvertex == 0)
			throw string("Aborting Program. \n");

		//Creating vertex
		Vertex* vertexlist = new Vertex[nbvertex];
		int val;

		for (int i = 0; i < nbvertex; i++)
		{
			cout << "Please enter data value for vertex " << i + 1 << ": ";
			cin >> val;
			vertexlist[i].setvalue(val);
		}

		//Prompting user for number of edge
		cout << "Please enter the number of edges you wish to create: ";
		int nbedge;
		cin >> nbedge;

		Edge* edgelist = new Edge[nbedge];


		//Note
		cout << "\nNote that to ease testing the graph will use the value of the id of the vertex and not the data value stored at each vertex. " << endl;
		cout << "Thus, since " << nbvertex << " vertices were created the ids will range from 1 to " << nbvertex << "." << endl;

		//Try loop
		bool valid = 0;
		while (!valid)
		{
			try
			{
				//Creating edges
				for (int t = 0; t < nbedge; t++)
				{
					//Prompting user
					cout << "Please enter the starting vertex for edge " << t + 1 << ": ";
					int startv;
					cin >> startv;
					if (startv > nbvertex)
						throw string("This vertex does not exist please try again.");


					cout << "Please enter the ending vertex for edge " << t + 1 << ": ";
					int endv;
					cin >> endv;
					if (endv > nbvertex)
						throw string("This vertex does not exist please try again.");


					//Adding to array
					Edge e1(1, vertexlist[startv - 1], vertexlist[endv - 1]);
					edgelist[t] = e1;
				}

				valid = 1;

			}
			catch (string errormsg)
			{
				cout << errormsg << endl;
			}
		}


		//Informing user
		cout << "\nThe following vertices and edges have been added to both the directed and undirected graphs." << endl;

		//Undirected
		und1.addVertices(vertexlist, nbvertex);
		und1.addEdges(edgelist, nbedge);
		//Displaying graph
		cout << "Displaying the undirected graph: " << endl;
		und1.display();

		//Directed
		directed1.addVertices(vertexlist, nbvertex);
		directed1.addEdges(edgelist, nbedge);
		//Displaying graph
		cout << "\nDisplaying the directed graph: " << endl;
		directed1.display();




		//Testing function 5
		cout << "Testing function 5." << endl;
		//Testing All paths functions
		cout << "\nAll paths for undirected graph:" << endl;
		und1.printAP();
		//Displaying All paths function
		cout << "\nAll paths for directed graph:" << endl;
		directed1.printAP();






		//Testing function 6
		cout << "\nTesting function 6." << endl;

		//Testing all paths for queried vertex
		int vertex1;

		while (true)
		{
			try
			{
				//Message prompt
				cout << "Testing queried vertex all possible paths\nPlease enter the starting vertex: ";
				cin >> vertex1;

				if (vertex1 > nbvertex)
					throw string("Vertex does not exist.\nPlease try again.\n");

				//Testing all paths with leading vertex
				cout << "\nAll possible paths from undirected graph with leading vertex " << vertex1 << ":" << endl;
				und1.printlead(vertex1);
				cout << "\nAll possible paths from directed graph with leading vertex " << vertex1 << ":" << endl;
				directed1.printlead(vertex1);

				break;
			}

			catch (string str)
			{
				cout << str;
				continue;
			}
		}


		//Testing function 7
		cout << "\nTesting function 7." << endl;
		cout << "Searching for an edge in the graph." << endl;
		cout << "Please enter id of starting vertex of edge: ";
		int startv;
		cin >> startv;
		cout << "Please enter id of ending vertex of edge: ";
		int endv;
		cin >> endv;

		if (und1.searchedge(startv, endv))
			cout << "This edge exists in the graph." << endl;
		else
			cout << "This edge does not exist in the graph." << endl;


		//Testing function 8
		cout << "\nTesting function 8." << endl;

		//Testing queried vertex value function
		cout << "Searching for vertex with value." << endl;
		cout << "Please enter the value of the vertex to search for: ";
		int dvalue;
		cin >> dvalue;
		und1.searchvertexvalue(dvalue);




		//Testing vertex removal
		cout << "\nTesting Vertex Remove function" << endl;
		und1.display();

		cout << "Enter ID of vertex you would like to remove: ";
		int remove;
		cin >> remove;

		cout << "Removing vertex " << remove << "." << endl;
		und1.removeVertex(vertexlist[remove - 1]);
		cout << "Graph now displays: " << endl;
		und1.display();






	}
	catch (string str)
	{
		cout << str;
		exit(1);
	}

	




	return 0;
}
