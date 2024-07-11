/* 13. Write a C++ program to delete the nth node of a Singly Linked List from the end.
Test nummber:
Original list:
7 5 3 1
Remove the 2nd node from the end of the said list:
Updated list:
7 5 1
Remove the 3rd node from the end of the said list:
Updated list:
5 1 */
#include<iostream>
using namespace std;
struct node{
	int number;
	node* next;
};
node* start = NULL;

int size = 0;
void insert(int value){
	node* temp = new node();
	temp->number = value;
	temp->next = NULL;
	if(start == NULL){
		start = temp;
	} 
	else{
		node* curr = start;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = temp;
	}
	size++;
}

void print(){
	node* curr = start;
	while(curr != NULL){
		cout<<curr->number<<"\t";
		curr = curr->next;
	}
}

void nodeDelete(int ind){
	node*curr = start;
	int count = 0;
	node* prev = NULL;
	while(curr != NULL){
		if(size - count == ind){
			node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            size--;
            break;
		}
		curr = curr->next;
		count++;	
	}
		
}

int main(){
	int num,n,ind;
	cout<<"Enter the elements of singly linked list:"<<endl;
	cin>>num;
	for(int i = 0; i<num; i++){
		cout<<"enter number:";
		cin>>n;
		insert(n);
	}
	cout<<"Original List:"<<endl;
    print();
    cout<<endl;
    cout<<"enter the index to delete the node at it: ";
    cin>>ind;
    cout<<endl;
		nodeDelete(ind);
    	print();


	return 0;
}

