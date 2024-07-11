/* 2. Write a C++ program to create a singly linked list of n nodes and display it in reverse order.
Test Data:
Original Linked list:
11 9 7 5 3 1
Reverse Linked list:
1 3 5 7 9 11 */

#include <iostream>
#include <cstdlib>
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

// Function to print the linked list in reverse order using recursion.
void reverse(node* curr) {
    if (curr == NULL) {
        return;  // Base case: end of the list.
    }
    reverse(curr->next); // Recursively traverse the list in reverse order.
    cout << curr->data << "\t"; // Print the data after the recursion returns.
}

int main() {
    // Insert data into the linked list.
    insertion(11);
    insertion(9);
    insertion(7);
    insertion(5);
    insertion(3);
    insertion(1);
    cout << "Original Linked list:" << endl;
    print();
    cout << endl << "Reverse Linked list:" << endl;
    reverse(start);

    return 0;
}


