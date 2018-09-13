
//William S. Sager
//Professor Nazarian
//EE450
//Credit: Sourced implementation of Bellman-Ford from geeksforgeeks.com

 
// shortest path algorithm.
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
#include <typeinfo>

using namespace std;

//Function Declarations:
void N7();
void N10();
void N20();


// a structure to represent a weighted edge in graph
struct Edge
{
	int src, dest, weight;
};

// a structure to represent a connected, directed and 
// weighted graph
struct Graph
{
	// V-> Number of vertices, E-> Number of edges
	int V, E;

	// graph is represented as an array of edges.
	struct Edge* edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}

// A utility function used to print the solution
void printArr(int dist[], int n)
{
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < n; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}

// The main function that finds shortest distances from src to
// all other vertices using Bellman-Ford algorithm. The function
// also detects negative weight cycle
void BellmanFord(struct Graph* graph, int src)
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];

	// Step 1: Initialize distances from src to all other vertices
	// as INFINITE
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	// Step 2: Relax all edges |V| - 1 times. A simple shortest 
	// path from src to any other vertex can have at-most |V| - 1 
	// edges
	for (int i = 1; i <= V-1; i++)
	{
		for (int j = 0; j < E; j++)
		{
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}

	// Step 3: check for negative-weight cycles. The above step 
	// guarantees shortest distances if graph doesn't contain 
	// negative weight cycle. If we get a shorter path, then there
	// is a cycle.
	for (int i = 0; i < E; i++)
	{
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
			printf("Graph contains negative weight cycle");
	}

	printArr(dist, V);

	return;
}


// Driver program to test above functions
int main()
{
	string userChoice;
	bool flag = false;
	cout<<"Would you like N7, N10, or N20?"<<"\nSelection: ";
	while (!flag)
		{
			cin>>userChoice;

			if (userChoice == "N7")
			{
				N7();
				flag = true;
			}
			else if (userChoice == "N10")
			{
				N10();
				flag = true;
			}
			else if (userChoice == "N20")
			{
				N20();
				flag = true;
			}
			else{
				cout<<"Please enter either N7, N10, or N20"<<endl;
			}
		}
	return 0;
}

void N7()
{
    int V = 7; // Number of vertices in graph
	int E = 20; // Number of edges in graph
	struct Graph* graph = createGraph(V, E);

	int edgeCount = 0;


	//take vales from csv and put them in a 2d array
	float data[7][7] = {0};
	bool flag = false;
    std::ifstream myfile("N7.csv");

    for(int row = 0; row < 7; ++row)
    {
        std::string line;
        std::getline(myfile, line);
        if ( !myfile.good() )
            break;

        std::stringstream iss(line);

        for (int col = 0; col < 7; ++col)
        {
            std::string val;
            std::getline(iss, val, ',');
            std::remove(val.begin(), val.end(), '\n');
            
            if ( !iss.good() )
            {
                break;
            }
            std::stringstream convertor(val);
            convertor >> data[row][col];

            //Apply Bellman-Ford to my 2d Vector

        }
    }
    int secondarCounter = 0;
    myfile.close();
    // Apply Bellman-Ford to 2D vector
    for (int i = 0; i < 7; ++i)
    {
    	for (int j = 0; j < 7; ++j)
    	{
    		
    		if (data[i][j] != 0)
    		{
    			graph->edge[edgeCount].src = i;
				graph->edge[edgeCount].dest = j;
				graph->edge[edgeCount].weight = data[i][j];
				edgeCount++;
 		   	}
 		}

	}
    BellmanFord(graph, 0);
    cout<<"\nedgeCount: "<<edgeCount<<"\n";
    cout<<"\nSecondaryCounter: "<<secondarCounter<<"\n";
}

void N10()
{
	cout<<"flag";
    int V = 10; // Number of vertices in graph
	int E = 34; // Number of edges in graph
	struct Graph* graph = createGraph(V, E);

	int edgeCount = 0;


	//take vales from csv and put them in a 2d array
	float data[10][10] = {0};
	bool flag = false;
    std::ifstream myfile("N10.csv");

    for(int row = 0; row < 10; ++row)
    {
        std::string line;
        std::getline(myfile, line);
        if ( !myfile.good() )
            break;

        std::stringstream iss(line);

        for (int col = 0; col < 10; ++col)
        {
            std::string val;
            std::getline(iss, val, ',');
            std::remove(val.begin(), val.end(), '\n');
            
            if ( !iss.good() )
            {
                break;
            }
            std::stringstream convertor(val);
            convertor >> data[row][col];
        }
    }
    myfile.close();
    cout<<"10 edgeCount"<<edgeCount;

    // Apply Bellman-Ford to 2D vector
    for (int i = 0; i < 10; ++i)
    {
    	for (int j = 0; j < 10; ++j)
    	{
    		
    		if (data[i][j] != 0)
    		{
    			graph->edge[edgeCount].src = i;
				graph->edge[edgeCount].dest = j;
				graph->edge[edgeCount].weight = data[i][j];
				edgeCount++;
 		   	}

    	}

	}
    BellmanFord(graph, 0);

}

void N20()
{
    int V = 20; // Number of vertices in graph
	int E = 170; // Number of edges in graph
	struct Graph* graph = createGraph(V, E);

	int edgeCount = 0;


	//take vales from csv and put them in a 2d array
	float data[20][20] = {0};
	bool flag = false;
    std::ifstream myfile("N20.csv");

    for(int row = 0; row < 20; ++row)
    {
        std::string line;
        std::getline(myfile, line);
        if ( !myfile.good() )
            break;

        std::stringstream iss(line);

        for (int col = 0; col < 20; ++col)
        {
            std::string val;
            std::getline(iss, val, ',');
            std::remove(val.begin(), val.end(), '\n');
            
            if ( !iss.good() )
            {
                break;
            }
            std::stringstream convertor(val);
            convertor >> data[row][col];
        }
    }
    myfile.close();
    // Apply Bellman-Ford to 2D vector
    for (int i = 0; i < 20; ++i)
    {
    	for (int j = 0; j < 20; ++j)
    	{
    		
    		if (data[i][j] != 0)
    		{
    			graph->edge[edgeCount].src = i;
				graph->edge[edgeCount].dest = j;
				graph->edge[edgeCount].weight = data[i][j];
				edgeCount++;
 		   	}

    	}

	}
    BellmanFord(graph, 0);
    cout<<"edgeCount"<<edgeCount;

}