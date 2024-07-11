#include<iostream>
#include<cstdlib>

// Linked List Insertion and Deletion using stack

struct node{
	int number;
	node* next;
	node* prev;
};

node* start = NULL;

// function to push a node ( Insertion ) 
void PushNode(){
	node* temp = new node(); // dynamically allocating memory to new node
	std::cout << "Enter a number: ";
	std::cin >> temp -> number;
	temp -> next = start; // The new node's next points to the current top
	temp -> prev = NULL; // The new node is the new top, so prev is NULL
	if (start != NULL){ // will only run when its first node
		start -> prev = temp;
	}
	start = temp; // Update the top pointer to the new node
}

// function to print the node
void print(){
	node* curr = start; // initialize curr pointer to start of list
	while(curr != NULL){ // loop will continue curr pointer qill not be null
		std::cout << "Number:" << "\t" << curr -> number ;
		std::cout << std::endl;
		curr = curr -> next; // moving the curr pointer to next node
	}
}

// since we are using stack, no middle node can be popped.
// Function to pop a node (Deletion)
void PopNode(){
	node* temp = start; 
	if(start != NULL)
	start = start -> next;
	start -> prev = NULL;
	free(temp);
}


int main()
{
	for(int i = 1 ; i < 7 ; i++){
		PushNode();
	}
	PopNode();
	print();
return 0;
}

