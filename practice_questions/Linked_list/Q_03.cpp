/* 3. Write a C++ program to create a singly linked list of n nodes and count the number of nodes.
Test Data:
Original Linked list:
13 11 9 7 5 3 1
Number of nodes in the said Linked list:
7
*/
#include <iostream>
using namespace std;
struct node{
  int number;
  node* next;
};
node* start = NULL;

void insert(int value) {
    node* temp = new node(); // Create a new node
    temp->number = value;     // Set the value of the new node
    temp->next = NULL;  // Set the next pointer of the new node to NULL (initially)  
    // Check if the linked list is empty (start is NULL)
    if (start == NULL) {
        start = temp;  // If it's empty, make the new node the start of the linked list
    }
    else {
        // If the list is not empty, traverse to the end to find the last node
        node* curr = start;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        // Set the next of the last node to the new node, effectively adding it to the end
        curr->next = temp;
    }
}

void count() {
    int ct = 0;
    node* curr = start;
    cout << "Original list is:" << endl;   
    // Traverse the linked list and count the nodes
    while (curr != NULL) {
        ct++;
        // Print the value of the current node
        cout << curr->number << "\t";
        // Move to the next node in the list
        curr = curr->next;
    } 
    // Print the number of nodes in the linked list
    cout << endl << "Number of nodes in the linked list is: " <<endl<< ct;
}


int main() {
    insert(13);
    insert(11);
    insert(9);
    insert(7);
    insert(5);
    insert(3);
    insert(1);
    count();
    return 0;
}
