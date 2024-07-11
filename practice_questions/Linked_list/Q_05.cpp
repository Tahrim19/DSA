/* 5. Write a C++ program to insert a new node at the end of a Singly Linked List.
Test Data:
Original Linked list:
13 11 9 7 5 3 1
Insert a new node at the end of a Singly Linked List:
13 11 9 7 5 3 1 0
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

void print() {
    node* curr = start; // Initialize a current pointer to the start of the list  
    // Traverse the list and print the values
    while (curr != NULL) {
        cout << curr->number << "\t";
        curr = curr->next;  // Move to the next node in the list
    }
}

int main() {
    insert(13);
    insert(11);
    insert(9);
    insert(7);
    insert(5);
    insert(3);
    insert(1);
    cout<<"Original linked list:"<<endl;
    print();
    insert(0);
    cout<<endl<<"Insert a new node at the end of a Singly Linked List:"<<endl;
    print();
    return 0;
}
