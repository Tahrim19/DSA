#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
	int ID;
	int marks;
	node* next = nullptr;
};

node* start = nullptr;

// function to insert node
void insert(){
	node* temp = new node(); // allocating memory for new node
	cout<<"enter id: ";
	cin>> temp -> ID;
	cout<<"enter marks: ";
	cin>>temp -> marks;
	temp -> next = nullptr; // setting pointer of new node to null
	node* curr = start;
	if(start == nullptr){
		start = temp;
		return;
	}
	else{
		while (curr->next != nullptr){
		curr = curr -> next;
	}
	curr ->next = temp; 
	}
	
}

// function to print the node
void print(){
	node * curr = start; // initialize current pointer to start of list
	while(curr != nullptr){ // loop will continue current pointer qill not be null
		cout<<"ID:" << curr -> ID << "\t";
		cout<<"Marks: " << curr -> marks;
		cout<<endl;
		curr = curr -> next; // moving the current pointer to next node
	}
}

// function to delete all the nodes
void deleteAll(){
	node* curr = start;
	while (curr != nullptr){
		node* temp = curr;
		curr = curr -> next;
		delete curr;
		
	}
}


// Function to delete a specific node with a given ID
int deleteSpecific(int tosearch) {
    node* curr = start; // Initialize a pointer to traverse the list
    node* prev = nullptr; // Initialize a pointer to keep track of the previous node

    while (curr != nullptr) { // Traverse the list until the end is reached
        if (curr->ID == tosearch) { // Check if the current node's ID matches the one to delete
            if (prev == nullptr) {
                // If the current node is the first node, update the start pointer to the next node
                start = curr->next;
            } else {
                // If the current node is not the first node, update the previous node's next pointer
                prev->next = curr->next;
            }
            delete curr; // Delete the current node
            return 1; // Return 1 to indicate successful deletion
        }

        prev = curr; // Move the previous pointer to the current node
        curr = curr->next; // Move the current pointer to the next node
    }

    return 0; // Return 0 to indicate that the specified ID was not found
}



int main()
{
	int tosearch;
	string input;
	
	for(int i =0 ; i<3 ; i++){
	insert();
	}
	
	print();
	
	cout<<" enter the ID to be deleted.";
	cin>> tosearch;
	cout << " deleteALL or deleteSpecific ?";
	cin >> input;
	if(input == "deleteAll"){
		deleteAll();
	}
	else if (input == "deleteSpecific"){
		deleteSpecific(tosearch);
		print();
	}
	else{
		cout<<" none option choosen so exiting the program";
		exit(0);
	}
	
}

