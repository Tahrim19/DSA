#include <iostream>
#include <stack>
using namespace std;  // BFS -> QUEUE and DFS -> STACK

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
int size = 0;

// Function to insert a new vertex into the adjacency list
void InsertVertex(char value) {
    Vertex* Vtemp = new Vertex();
    Vtemp->data = value;
    Vtemp->next = NULL;
    Vtemp->Estart = NULL;  // Initialize the edge linked list for this vertex

    if (Vstart == NULL) {
        Vstart = Vtemp;  // If the adjacency list is empty, set the new vertex as the start
        size++;
    } else {
        Vertex* Vcurr = Vstart;
        while (Vcurr->next != NULL) {
            Vcurr = Vcurr->next;
        }
        Vcurr->next = Vtemp;  // Traverse to the end of the list and link the new vertex
        size++;
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


// Define a depth-first search (DFS) function that takes the starting vertex and a visited array
void DFS(char startVertex, bool visited[]) {
    // Output the current vertex
    cout << startVertex << " ";
    // Mark the current vertex as visited
    visited[startVertex - 'A'] = true;    
    // Start iterating through the list of vertices
    Vertex* Vcurr = Vstart;
    while (Vcurr != NULL) {
        // Check if the current vertex in the iteration matches the starting vertex
        if (Vcurr->data == startVertex) {
            // Start iterating through the list of edges for the current vertex
            Edge* Ecurr = Vcurr->Estart;
            while (Ecurr != NULL) {
                // Check if the adjacent vertex is not visited
                if (!visited[Ecurr->EData - 'A']) {   // 'A' is subtracted from Ecurr->EData, which effectively converts the character to an index value.
                    // Recursively call the DFS function for the adjacent vertex
                    DFS(Ecurr->EData, visited);
                }
                Ecurr = Ecurr->next; // Move to the next adjacent vertex
            }
            break; // Exit the loop after processing adjacent vertices
        }
        Vcurr = Vcurr->next; // Move to the next vertex in the list
    }
}


bool vertexExists(char vertex) {
    Vertex* Vcurr = Vstart;
    while (Vcurr != NULL) {
        if (Vcurr->data == vertex) {
            return true; // Vertex exists in the graph
        }
        Vcurr = Vcurr->next;
    }
    return false; // Vertex doesn't exist in the graph
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
    InsertEdge('C', 'E');
    
    InsertEdge('D', 'A');
    InsertEdge('D', 'G');
    
    InsertEdge('E', 'B');
    InsertEdge('E', 'C');
    InsertEdge('E', 'G');
    
    InsertEdge('F', 'A');
	
	InsertEdge('G', 'D');
	InsertEdge('G', 'E');

    printAdjacencyList();
    
    cout<<"Number of vertices: "<<size<<endl;
    
    cout<<"Enter root node: ";
	cin>>v;
    if(vertexExists(v)){
    	bool visited[size] = {false};
	    DFS(v,visited);
	}
	else{
		cout<<"Vertex doesnt exist!";
	}

	return 0;
}
