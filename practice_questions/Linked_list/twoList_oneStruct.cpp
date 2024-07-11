#include <iostream>
using namespace std;

/* Using '&' in the function parameter void insert(Node*& start, int value) doesn't dereference the start pointer.
 It allows you to pass the pointer by reference, meaning that you can directly modify the pointer itself. 
 Dereferencing a pointer is done with *, like *start, which would give you the value it points to.In your function, 
 if you wanted to dereference the start pointer and work with the data it points to, you would use *start within the function.
 But in this case, you are passing the pointer start by reference to modify it, not the data it points to.*/

struct Node {              
    int number;
    Node* next;
    Node* prev;
};

Node* start_L1 = NULL;
Node* start_L2 = NULL;

// Function to insert a new node into the specified linked list
void insert(Node*& start, int value) {
    Node* temp = new Node();
    temp->number = value;
    temp->next = NULL;

    if (start == NULL) {
        start = temp;
        temp->prev = NULL;
    } else {
        Node* curr = start;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    }
}

// Function to print the elements of a linked list
void print(Node* start) {
    Node* curr = start;
    while (curr != NULL) {
        cout << curr->number << "\t";
        curr = curr->next;
    }
}



int main() {
	for(int i=7; i<=42 ;i = i+7 ){
		insert(start_L1, i);
	}
	for(int i=3; i<=18 ;i = i+3 ){
		insert(start_L2, i);
	}
    cout << "List 1: ";
    print(start_L1);
    cout << endl << "List 2: ";
    print(start_L2);

    return 0;
}


