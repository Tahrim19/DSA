/* 10. Write a C++ program to delete first node of a given Singly Linked List.
Test Data:
Original Linked list:
13 11 9 7 5 3 1
Delete first node of Singly Linked List:
11 9 7 5 3 1 */
#include<iostream>
using namespace std;
struct node{
	int number;
	node* next;	
};
node* start = NULL;
 
void insert(int data){
	node* temp = new node();
	temp->number = data;
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
}

void print(){
	node* curr = start;
	while(curr != NULL){
		cout<<curr->number<<"\t";
		curr = curr->next;
	}
	cout<<endl;
}

void deleteNode(){
	if(start != NULL){
		node* temp = start;
		start = start->next;
		delete(temp);
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
    deleteNode();
    print();
	return 0;
}

