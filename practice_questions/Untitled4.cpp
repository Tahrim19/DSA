#include <iostream>
#include<vector>
#include<unordered_set>
#include<climits>
using namespace std;

// Define a structure for an edge in the adjacency list
struct Edge {
    char EData;
    Edge* next;
};

// Define a structure for a vertex in the adjacency list
struct Vertex {
    char data;       
    Vertex* next;    
    Edge* Estart;    // Pointer to the start of the linked list of edges
};

Vertex* Vstart = NULL;  // Initialize the start of the adjacency list as NULL

// Function to insert a new vertex into the adjacency list
void InsertVertex(char value) {
    Vertex* Vtemp = new Vertex();
    Vtemp->data = value;
    Vtemp->next = NULL;
    Vtemp->Estart = NULL;  // Initialize the edge linked list for this vertex

    if (Vstart == NULL) {
        Vstart = Vtemp;  // If the adjacency list is empty, set the new vertex as the start
    } else {
        Vertex* Vcurr = Vstart;
        while (Vcurr->next != NULL) {
            Vcurr = Vcurr->next;
        }
        Vcurr->next = Vtemp;  // Traverse to the end of the list and link the new vertex
    }
}

// Function to insert a new edge from 'fromValue' to 'toValue'
void InsertEdge(char fromValue, char toValue) {
    Vertex* fromVertex = Vstart;
    while (fromVertex != NULL) {
        if (fromVertex->data == fromValue) {
            Edge* Etemp = new Edge();
            Etemp->EData = toValue;
            Etemp->next = NULL;

            if (fromVertex->Estart == NULL) {
                fromVertex->Estart = Etemp;  // If there are no edges, set the new edge as the start
            } else {
                Edge* Ecurr = fromVertex->Estart;
                while (Ecurr->next != NULL) {
                    Ecurr = Ecurr->next;
                }
                Ecurr->next = Etemp;  // Traverse to the end of the edge list and link the new edge
            }
            return;
        }
        fromVertex = fromVertex->next;
    }
}

// Function to print the adjacency list
void printAdjacencyList() {
    Vertex* Vcurr = Vstart;
    while (Vcurr != NULL) {
        cout << Vcurr->data << " -> ";
        Edge* Ecurr = Vcurr->Estart;
        while (Ecurr != NULL) {
            cout << Ecurr->EData << " ";
            Ecurr = Ecurr->next;
        }
        cout << endl;
        Vcurr = Vcurr->next;
    }
}


// Function to find the minimum spanning tree using Prim's algorithm
void findMinimumSpanningTree() {
    unordered_set<char> visited;
    vector<Edge> mstEdges;

    // Choose a starting vertex at random (in this case, the first vertex)
    visited.insert(Vstart->data);

    while (visited.size() < Vstart->data - 'A' + 1) {
        int minWeight = INT_MAX;
        Edge minEdge;

        for (char v : visited) {
            Vertex* vertex = Vstart;
            while (vertex != NULL) {
                if (vertex->data == v) {
                    Edge* edge = vertex->Estart;
                    while (edge != NULL) {
                        if (visited.find(edge->EData) == visited.end() && edge->weight < minWeight) {
                            minWeight = edge->weight;
                            minEdge = *edge;
                        }
                        edge = edge->next;
                    }
                }
                vertex = vertex->next;
            }
        }

        visited.insert(minEdge.EData);
        mstEdges.push_back(minEdge);
    }

    cout << "Minimum Spanning Tree Edges:" << endl;
    for (const Edge& edge : mstEdges) {
        cout << Vstart->data << " - " << edge.EData << " (Weight: " << edge.weight << ")" << endl;
    }
}


int main() {
	char v;
    // Insert vertices into the adjacency list
    InsertVertex('A');
    InsertVertex('B');
    InsertVertex('C');
    InsertVertex('D');
    InsertVertex('E');
    InsertVertex('F');
    InsertVertex('G');
    
    // Insert edges to create the directed graph
    InsertEdge('A', 'B');
    InsertEdge('A', 'D');
    InsertEdge('A', 'F');
    
    InsertEdge('B', 'C');
    InsertEdge('B', 'E');
    
    InsertEdge('C', 'A');

    InsertEdge('D', 'G');
    
    InsertEdge('E', 'C');
    
    InsertEdge('F', 'A');
    InsertEdge('G', 'E');
    
	
    findMinimumSpanningTree();

	return 0;
}
