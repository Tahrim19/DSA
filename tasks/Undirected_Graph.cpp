#include <iostream>
using namespace std;

// Define a structure for an edge in the adjacency list
struct Edge {
    char toVertex;
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
            Etemp->toVertex = toValue;
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
            cout << Ecurr->toVertex << " ";
            Ecurr = Ecurr->next;
        }
        cout << endl;
        Vcurr = Vcurr->next;
    }
}

int UndirectedDegree(char data) {
    int count = 0;
    Vertex* Vcurr = Vstart;
    while (Vcurr != NULL) {
        if (Vcurr->data == data) {
            Edge* Ecurr = Vcurr->Estart;
            while (Ecurr != NULL) {
                count++;
                Ecurr = Ecurr->next;
            }
        }
        Vcurr = Vcurr->next;
    }

    return count;
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

    // Insert edges to create the undirected graph
    InsertEdge('A', 'B');
    InsertEdge('A', 'D');
    InsertEdge('A', 'F');
    InsertEdge('A', 'C');
    
    InsertEdge('B', 'A');
    InsertEdge('B', 'C');
    InsertEdge('B', 'E');
    
    InsertEdge('C', 'B');
    InsertEdge('C', 'A');
    InsertEdge('C', 'F');
    
    InsertEdge('D', 'A');
    InsertEdge('D', 'G');
    
    InsertEdge('E', 'B');
    InsertEdge('E', 'C');
    InsertEdge('E', 'G');
    
    InsertEdge('F', 'A');
	
	InsertEdge('G', 'D');
	InsertEdge('G', 'E');
    
    // Print the adjacency list to visualize the graph
    printAdjacencyList();
    
    cout<<"Enter the vertex of which the degree is to be known: ";
    cin>>v;
    int a = UndirectedDegree(v);
	cout<<"the no. of nodes are: "<< a;
    return 0;
}

