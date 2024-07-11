/* 4. Write a C++ program to insert a new node at the beginning of a Singly Linked List.
Test Data:
Original Linked list:
13 11 9 7 5 3 1
Insert a new node at the beginning of a Singly Linked List:
0 13 11 9 7 5 3 1
*/
#include <iostream>
using namespace std;
struct node{
  int number;
  node* next;
};
node* start = NULL;

void insert(int value) {  
    node* temp = new node(); // Create a new node.  
    temp->number = value;   // Set the value of the new node 
    temp->next = start;  // Set the next pointer of the new node to point to the current start node
    start = temp;   // Update the start pointer to point to the new node, effectively inserting it at the beginning
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
	insert(1);
    insert(3);
    insert(5);
    insert(7);
    insert(9);
    insert(11);
    insert(13);
    cout<<"Original linked list:"<<endl;
    print();
    insert(0);
    cout<<endl<<"Insert a new node at the beginning of a Singly Linked List:"<<endl;
    print();
	return 0;
}
