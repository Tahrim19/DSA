/* 9. Write a C++ program to insert a new node at any position of a Singly Linked List.
Test Data:
Original list:
7 5 3 1
Position: 1, Value: 12
Updated list:
12 7 5 3 1 */
#include<iostream>
using namespace std;
struct node{
	int number;
	node* next;
};
node* start = NULL;

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

// Function to insert a new node at the specified position
int position(int pos, int v) {
    int count = 1;
    node* curr = start;
    while (curr != NULL) {
        if (count == pos) {
            // Create a new node
            node* temp = new node;
            // Set the value of the new node
            temp->number = v;
            // Connect the new node to the next node in the list
            temp->next = curr->next;
            // Connect the current node to the new node
            curr->next = temp;
            // Return the number in the new node
            return (temp->number);
        }
        count++;
        // Move to the next node in the list
        curr = curr->next;
    }
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
	cout<<"Original List:"<<endl;
    print();
	int pos, v;
    cout<<endl<<"enter the postion at which you want to insert new node"<<endl; 
    cin>>pos;
    if(pos>num){
		cout<<"index out of bounds!";
	}
	else{
	    cout<<"enter the value ";
	   	cin>>v;
		position(pos,v);
    	print();
	}
	return 0;
}
