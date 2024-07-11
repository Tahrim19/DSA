/* 11. Write a C++ program to delete a node from the middle of Singly Linked List.
Test Data:
Original list:
9 7 5 3 1
After removing the middle element of the said list:
9 7 3 1 */
#include<iostream>
using namespace std;
struct node{
	int number;
	node* next;	
};
node* start = NULL;
int list_size = 0;
// Function to insert a new node at the end of the linked list
void insert(int value) {
    // Create a new node
    node* temp = new node();
    // Set the value of the new node
    temp->number = value;
    // Initialize the 'next' pointer to NULL
    temp->next = NULL;
    
    // Check if the linked list is empty
    if (start == NULL) {
        // If empty, set the start pointer to the new node
        start = temp;
    } else {
        // If not empty, traverse to the end of the list
        // and connect the last node to the new node
        node* curr = start;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
    }
    list_size++;
}

// Function to print the elements of the linked list
void print() {
    // Start from the beginning of the list
    node* curr = start;
    while (curr != NULL) {
        // Print the number in the current node
        cout << curr->number << "\t";
        // Move to the next node
        curr = curr->next;
    }
}

// this will be the bad approach as it would increase the time complexity
void deleteNode() {
    if (start == NULL) {
        // Check if the list is empty
        cout << "Empty list." << endl;
        return;
    }
    if (start->next == NULL) {
        // If there's only one node in the list, delete it and set the start pointer to NULL
        delete start;
        start = NULL;
        return;
    }
    int count = 0;
    int middle;
    node* curr = start;
    // Count the number of nodes in the list
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    // Calculate the position of the middle node
    middle = count / 2;
    curr = start;
    count = 1;
    // Traverse the list to find the node just before the middle node
    while (count < middle) {
        curr = curr->next;
        count++;
    }
    // Delete the middle node by adjusting the next pointer of the previous node
    node* temp = curr->next;
    curr->next = temp->next;
    delete temp;
    list_size--;
    cout<<"list size is:"<<list_size<<endl;
}


// function to delete the middle node using two pointer approach 
void delNode() {
    if (start == NULL) {
        // Check if the list is empty
        cout << "List is empty." << endl;
    }
    if (start->next == NULL) {
        // If there's only one node in the list, delete it and set the start pointer to NULL
        delete start;
        start = NULL;
        return;
    }
    // Initialize slow and fast pointers to traverse the list
    node* slow = start;
    node* fast = start;
    // Traverse the list using fast-slow pointers
    while (fast != NULL && fast->next != NULL) {
        // Move slow one step at a time
        slow = slow->next;
        // Move fast two steps at a time
        fast = fast->next->next;
    }
    // The slow pointer is now pointing to the middle node
    // Copy the data from the next node to the current node
    node* temp = slow->next;
    slow->number = temp->number;
    // Adjust the next pointer of the current node to skip the middle node
    slow->next = temp->next;
    // Delete the middle node
    delete temp;
    list_size--;
    cout<<"list size is:"<<list_size<<endl;
}


// Function to remove a node at a specific position
void remove(int pos) {
    int i = 1;           // Initialize a counter
    node* curr = start;   // Start from the beginning of the list
    // Traverse the list until the end is reached or the desired position is reached
    while (curr != NULL) {
        if (i == pos) {    // Check if the current node is at the specified position
            // Create a temporary pointer to the next node
            node* temp = curr->next;
            // Adjust the 'next' pointer of the current node to skip the node to be removed
            curr->next = temp->next;
            // Delete the node to be removed
            delete temp;
            // Decrease the list size since a node has been removed
            list_size--;
            // Exit the loop since the node has been removed
            break;
        }
        // Move to the next node and increment the counter
        curr = curr->next;
        i++;
    }
    cout<<"list size: "<<list_size<<endl;
}


int main(){
	int num,n,e;
	cout<<"Enter the elements of singly linked list:"<<endl;
	cin>>num;
	for(int i = 0; i<num; i++){
		cout<<"enter number:";
		cin>>n;
		insert(n);
	}
	cout<<"size of list: "<<list_size<<endl;
	cout<<"Original List:"<<endl;
    print();
    cout<<endl;
    int pos = list_size/2;
    remove(pos);
    print();
    cout<<endl;
    deleteNode();
    print();
    cout<<endl;
    delNode();
    print();
    
	return 0;
}

