#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure for an edge in the adjacency list
struct Edge {
    char E_Data; // Destination vertex of the edge
    int weight;  // Weight of the edge
    Edge* next;  // Pointer to the next edge in the list
};

// Define a structure for a vertex in the adjacency list
struct Vertex {
    char data;     // Data associated with the vertex
    Vertex* next;  // Pointer to the next vertex in the list
    Edge* E_start; // Pointer to the start of the list of edges
    bool visited;
};

struct Vertex* Vstart = NULL; // Initialize the start of the vertex list to null
int size = 0; // Initialize the number of vertices to 0

// Maintain a counter for the number of edges
int numEdges = 0;

// Maintain an array of weights for the edges
int weights[50]; 

// Function to insert a new vertex into the adjacency list
void Insert_Vertex(char value) {
    // Create a new vertex with the given data
    struct Vertex* V_temp = new Vertex();
    V_temp->data = value;
    V_temp->next = NULL;    // Initialize the next pointer to null
    V_temp->E_start = NULL; // Initialize the list of edges to null
    V_temp->visited = false; // Initialize the visited flag

    if (Vstart == NULL) {
        Vstart = V_temp; // If the list is empty, set the new vertex as the start
    } else {
        struct Vertex* V_curr = Vstart;
        while (V_curr->next != NULL) {
            V_curr = V_curr->next; // Traverse the list to find the last vertex
        }
        V_curr->next = V_temp; // Add the new vertex at the end of the list
    }
    size++; // Increment the count of vertices
}

// Function to insert a new edge from 'from_Value' to 'to_Value' with a weight
void Insert_Edge(char from_Value, char to_Value, int weightValue) {
    struct Vertex* from_Vertex = Vstart;

    while (from_Vertex != NULL) {
        if (from_Vertex->data == from_Value) {
            // Create a new edge with the destination vertex and weight
            struct Edge* E_temp = new Edge();
            E_temp->E_Data = to_Value;
            E_temp->weight = weightValue;
            E_temp->next = NULL;

            if (from_Vertex->E_start == NULL) {
                from_Vertex->E_start = E_temp; // If no edges exist, set the new edge as the first edge
            } else {
                struct Edge* E_curr = from_Vertex->E_start;
                while (E_curr->next != NULL) {
                    E_curr = E_curr->next; // Traverse the list of edges to find the last edge
                }
                E_curr->next = E_temp; // Add the new edge to the end of the list
            }

            // Store the weight in the weights array using the numEdges as the index
            weights[numEdges] = weightValue;
            numEdges++; // Increment the count of edges

            return;
        }
        from_Vertex = from_Vertex->next;
    }
}

// Function to print the adjacency list, including weights
void print_Adjacency_List() {
    Vertex* V_curr = Vstart;
    while (V_curr != NULL) {
        std::cout << V_curr->data << " -> ";
        Edge* E_curr = V_curr->E_start;
        while (E_curr != NULL) {
            std::cout << E_curr->E_Data << "(" << E_curr->weight << ") "; // Print the destination vertex and edge weight
            E_curr = E_curr->next;
        }
        std::cout << std::endl;
        V_curr = V_curr->next;
    }
}

// Define a structure for a disjoint set
struct DisjointSet {
    vector<int> parent; // An array to represent the parent of each vertex

    // Constructor to initialize the disjoint set with 'n' vertices
    DisjointSet(int n) : parent(n, -1) {} // Initialize all parent values to -1 (indicating individual sets)

    // Function to find the parent (representative) of a vertex
    int find(int vertex) {
        if (parent[vertex] == -1)
            return vertex; // If the parent is -1, this vertex is its own representative
        return find(parent[vertex]); // Otherwise, recursively find the parent's representative
    }

    // Function to unite two sets (vertices 'a' and 'b')
    void unite(int a, int b) {
        int parentA = find(a); // Find the representative of set 'a'
        int parentB = find(b); // Find the representative of set 'b'
        if (parentA != parentB) {
            parent[parentB] = parentA; // Set 'b's representative to 'a', uniting the sets
        }
    }
};

// Function to get the index of a vertex by its value
int getIndexByValue(char value) {
    int index = 0;
    Vertex* V_curr = Vstart;
    while (V_curr != NULL) {
        if (V_curr->data == value) {
            return index; // Return the index of the vertex with the specified value
        }
        V_curr = V_curr->next;
        index++; // Increment the index for the next iteration
    }
    // Return an invalid index or handle the case when the value is not found
    return -1; // You can choose an appropriate error value if needed
}

// Function to perform Kruskal's algorithm
int kruskal() {
    // Create a vector to store the edges in the format (weight, (from, to))
    vector<pair<int, pair<char, char> > > edges;

    // Add all edges to the vector
    Vertex* V_curr = Vstart;
    while (V_curr != NULL) {
        Edge* E_curr = V_curr->E_start;
        while (E_curr != NULL) {
            char from_Value = V_curr->data;
            char to_Value = E_curr->E_Data;
            int weightValue = E_curr->weight;
            edges.push_back(make_pair(weightValue, make_pair(from_Value, to_Value))); // Store edge details in the vector
            E_curr = E_curr->next;
        }
        V_curr = V_curr->next;
    }

    // Sort edges in non-decreasing order of weight
    sort(edges.begin(), edges.end());

    int mstCost = 0; // Initialize the cost of the Minimum Spanning Tree (MST) to 0
    int edgesAdded = 0; // Keep track of how many edges are added to the MST, starting at 0

    DisjointSet ds(size); // Define a disjoint set with the number of vertices

    for (int i = 0; i < edges.size(); i++) {
        int weightValue = edges[i].first;
        char from_Value = edges[i].second.first;
        char to_Value = edges[i].second.second;

        int fromIndex = getIndexByValue(from_Value); // Get the index of the source vertex by its value
        int toIndex = getIndexByValue(to_Value); // Get the index of the destination vertex by its value

        int parentFrom = ds.find(fromIndex); // Find the parent of the source vertex
        int parentTo = ds.find(toIndex); // Find the parent of the destination vertex

        if (parentFrom != parentTo) {
            // If the parents of the source and destination vertices are different, include this edge in the MST
            cout << from_Value << " - " << to_Value << " (" << weightValue << ")" << endl; // Print the edge added to the MST
            mstCost += weightValue; // Add the edge's weight to the cost of the MST

            // Merge the sets of the source and destination vertices
            ds.unite(parentFrom, parentTo);

            edgesAdded++; // Increment the count of added edges
            if (edgesAdded == size - 1) {
                break; // The MST is complete
            }
        }
    }

    return mstCost; // Return the cost of the MST
}


int main() {
    // Insert vertices into the adjacency list
    Insert_Vertex('A');
    Insert_Vertex('B');
    Insert_Vertex('C');
    Insert_Vertex('D');
    Insert_Vertex('E');
    Insert_Vertex('F');
    Insert_Vertex('G');
    Insert_Vertex('H');
    Insert_Vertex('I');
    Insert_Vertex('J');
    Insert_Vertex('K');
    Insert_Vertex('L');

    // Insert edges to create the directed graph
    Insert_Edge('A', 'B', 2);
    Insert_Edge('A', 'D', 2);
    Insert_Edge('A', 'C', 3);
    Insert_Edge('B', 'H', 5);
    Insert_Edge('C', 'G', 1);
    Insert_Edge('D', 'F', 3);
    Insert_Edge('D', 'E', 2);
    Insert_Edge('E', 'F', 2);
    Insert_Edge('E', 'J', 6);
    Insert_Edge('G', 'I', 2);
    Insert_Edge('G', 'J', 2);
    Insert_Edge('H', 'G', 2);
    Insert_Edge('I', 'L', 1);
    Insert_Edge('I', 'J', 1);
    Insert_Edge('J', 'K', 5);



    print_Adjacency_List();
    cout << "Total number of vertices: " << size << endl;
	
	 int mstCost = kruskal();
    cout << "Total cost of the minimum spanning tree: " << mstCost << endl;
	 
    return 0;
}

