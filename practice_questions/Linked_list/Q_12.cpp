/* 12. Write a C++ program to delete the last node of a Singly Linked List.
Test Data:
Original list:
7 5 3 1
Remove the last node of the said list:
Updated list:
7 5 3  */
#include<iostream>
using namespace std;
using namespace std;
struct node{
	int number;
	node* next;	
};
node* start = NULL;
int size = 0;
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
    size++;
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

void deleteLast(){
	if(start == NULL){
		cout<<"list is empty";
	}
	if(start->next == NULL){
		delete start;
		cout<<"the list has been emptied";
	}
	node* curr = start;
	while(curr->next->next != NULL){
		curr = curr->next;
	}
	delete curr->next;
	curr->next = NULL;
	size--;
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
	cout<<"size of list: "<<size<<endl;
	cout<<"Original List:"<<endl;
    print();
    cout<<endl;
    
    deleteLast();
    cout<<"size of list: "<<size<<endl;
    print();
    cout<<endl;
    
    deleteLast();
    cout<<"size of list: "<<size<<endl;
    print();
    cout<<endl;
 

	return 0;
}

