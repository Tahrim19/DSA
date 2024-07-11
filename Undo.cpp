#include <iostream>
using namespace std;

// Define a structure for a node in the main stack
struct node {
    int number;     // Data in the node
    node* next;     // Pointer to the next node
    node* prev;     // Pointer to the previous node
};

node* top = NULL; // Pointer to the top of the main stack

// Define a structure for a node in the popped values stack
struct poppedNode {
    int num;            // Data in the node
    poppedNode* Pnext;  // Pointer to the next popped node
    poppedNode* Pprev;  // Pointer to the previous popped node
};

poppedNode* Ptop = NULL; // Pointer to the top of the popped values stack
int undoCount = 0; // Keep track of the number of undo operations

// Function to push a new node onto the main stack
void pushNode() {
    node* temp = new node(); // Create a new node
    cout << "Enter number: ";
    cin >> temp->number;    // Input data for the node
    temp->next = top;
    temp->prev = NULL;
    if (top != NULL) {
        top->prev = temp;
    }
    top = temp;
    // Handle the case when Ptop is NULL
    if (Ptop != NULL) {
        Ptop->Pprev = NULL;
    }
}

// Function to print the elements in the main stack
void print() {
    node* curr = top;
    while (curr != NULL) {
        cout << "number: " << curr->number << endl;
        curr = curr->next;
    }
}

// Function to pop an element from the main stack and push it onto the popped values stack
void popNode() {
    if (top != NULL) {
        poppedNode* box = new poppedNode(); // Create a new node for popped values
        box->num = top->number;             // Copy the value from the main stack node
        box->Pnext = Ptop;
        box->Pprev = NULL;
        if (Ptop != NULL) {
            Ptop->Pprev = box;
        }
        Ptop = box;

        node* temp = top;       // Store the current top node
        top = top->next;        // Move the top to the next node
        if (top != NULL) {
            top->prev = NULL; // Update the previous pointer of the new top node
        }
        delete temp;            // Delete the old top node to free memory
    } else {
        cout << "List is empty! Nothing to pop";
    }
}

// Function to print the popped values from the popped values stack
void printPoppedNode() {
    poppedNode* Pcurr = Ptop; // Initialize Pcurr to point to the top of the popped values stack
    int count = 0; // Initialize a count variable to track how many values have been printed

    // Loop through the popped values stack until we reach the end (Pcurr is NULL)
    while (Pcurr != NULL && count < undoCount) {
        cout << "undo: " << Pcurr->num << endl;  
        Pcurr = Pcurr->Pnext;   // Move to the next popped value in the stack
        count++;   // Increment the count to keep track of printed values
    }
}


int main() {
    string input;
for (int i = 0; i < 7; i++) {
    pushNode(); // Push nodes onto the main stack
}
print(); // Print the initial contents of the main stack

for (int i = 0; i < 7; i++) {  
    cout << "Do you want to pop the node? (y/n): ";
    cin >> input;
    if (input != "n") {
        popNode(); // Pop a node from the main stack
        undoCount = 0; // Reset the undo count as we are altering the main stack
        cout << "List after popping:" << endl;
        print(); // Print the main stack contents after popping
    } else {
        break; // Exit the loop if the user doesn't want to pop further
    }
}   

for (int j = 0; j < 5; j++) {
    cout << "Do you want to undo? (y/n): ";
    cin >> input;
    if (input == "y") {
        undoCount++; // Increment the undo count to track how many undo operations
        printPoppedNode(); // Print popped values if the user wants to undo
    } else {
        break; // Exit the loop if the user doesn't want to undo further
    }
}

return 0;

}
