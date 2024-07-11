/* 1. Write a C++ program to create and display a Singly Linked List.
Test Data:
The list contains the data entered:
11 9 7 5 3 1 */

#include <iostream>
using namespace std;

// Define a structure for a singly linked list node.
struct node {
    int data;
    node* next;
};

// Initialize the start pointer to NULL (an empty list).
node* start = NULL;

// Function to insert a new node with the given data at the end of the linked list.
void insertion(int data) {
    // Create a new node.
    node* temp = new node();
    temp->data = data;
    temp->next = NULL;

    if (start == NULL) {
        // If the list is empty, the new node becomes the first node.
        start = temp;
    } else {
        // If the list is not empty, find the last node and make it point to the new node.
        node* curr = start;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

// Function to print the linked list.
void print() {
    node* curr = start;
    while (curr != NULL) {
        cout << curr->data << "\t"; // Print the data of the current node.
        curr = curr->next;
    }
}

int main() {
    cout << "The list contains the data entered:" << endl;
    insertion(11);
    insertion(9);
    insertion(7);
    insertion(5);
    insertion(3);
    insertion(1);
    print();  // Print the linked list.

    return 0;
}

