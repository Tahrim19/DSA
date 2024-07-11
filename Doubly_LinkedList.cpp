#include<iostream>
#include<cstdlib>
using namespace std;

struct node{
	int ID;
	int marks;
	node* next = nullptr;
	node* prev = nullptr;
	
};

node* start = nullptr;

void insertNode(){
	node* temp = new node();
	cout<<"enter id: ";
	cin>> temp -> ID;
	cout<<"enter marks: ";
	cin>>temp -> marks;
	temp -> next = nullptr; 
	temp -> prev = nullptr; 
	node* curr = start;
	if(start == nullptr){
		start = temp;
	}
	else{
	while(curr->next != nullptr){
		curr = curr -> next;
	}
	curr -> next = temp;
	temp -> prev = curr; 
    }
	
}


void print(){
	node* curr = start;
	cout<<endl;
	while(curr != nullptr){
		cout<<"ID:" << curr -> ID << "\t";
		cout<<"Marks: " << curr -> marks;
		cout<<endl;
		curr = curr -> next; // moving the current pointer to next node
	}
	
}


int DeleteSpecific(int toSearch) {
    node* curr = start;
    while (curr != nullptr) {
        if (curr->ID == toSearch) {
            if (curr->prev == nullptr) {
                // If the current node is the first node, update the start pointer to the next node
                start = curr->next;
            } else {
                // If the current node is not the first node, update the previous node's next pointer
                curr->prev->next = curr->next;
            }
            if (curr->next != nullptr) {
                // Update the next node's previous pointer if it exists
                curr->next->prev = curr->prev;
            }
            node* temp = curr->next; // Store the next node before deleting the current node
            delete curr; // delete current node
            curr = temp; // Move to the next node
            return 1; // Indicate successful deletion
        }
        // Move the current pointer to the next node
        curr = curr->next;
    }
    return 0; // Indicate that the specified ID was not found
}

int main()
{
	for(int i =0; i<3; i++){
		insertNode();
	}
	cout<<"Before Deleting Specific Search ID";
	print ();
	
	int toSearch;
	cout << "Enter 'toSearch' ID: " << endl;
	cin >> toSearch;
	
	DeleteSpecific(toSearch);
	cout<<"After Deleting Specific Search ID" << endl;
	print();
	
return 0;
}

