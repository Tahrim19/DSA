#include <iostream>
#include <queue>
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


void BFS(char startVertex, bool visited[]) {
    cout << "BFS starting from vertex " << startVertex << ": ";
    queue<char> bfsQueue;

    visited[startVertex - 'A'] = true; // Mark the start vertex as visited
    bfsQueue.push(startVertex); // Push the start vertex into the queue

    while (!bfsQueue.empty()) {
        char currentVertex = bfsQueue.front(); // Get the front vertex from the queue
        cout << currentVertex << " "; // Output the current vertex
        bfsQueue.pop(); // Remove the current vertex from the queue

        Vertex* Vcurr = Vstart;
        while (Vcurr != NULL) {
            if (Vcurr->data == currentVertex) {
                Edge* Ecurr = Vcurr->Estart; // Get the linked list of edges for the current vertex
                while (Ecurr != NULL) {
                    char adjacentVertex = Ecurr->EData; // Get an adjacent vertex from the edge list
                    if (!visited[adjacentVertex - 'A']) {
                        visited[adjacentVertex - 'A'] = true; // Mark the adjacent vertex as visited
                        bfsQueue.push(adjacentVertex); // Push the adjacent vertex into the queue
                    }
                    Ecurr = Ecurr->next; // Move to the next adjacent vertex
                }
                break; // Exit the loop after processing adjacent vertices of the current vertex
            }
            Vcurr = Vcurr->next; // Move to the next vertex in the adjacency list
        }
    }
    cout << endl;
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
	    BFS(v,visited);
	}
	else{
		cout<<"Vertex doesnt exist!";
	}

	return 0;
}
