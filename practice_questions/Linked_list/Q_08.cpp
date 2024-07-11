/* 8. Write a C++ program to get Nth node in a given Singly Linked List.
Test Data:
Original list:
7 5 3 1
Position: 1
Value: 7 */
#include<iostream>
using namespace std;
struct node{
  int number;
  node* next;
};
node* start = NULL;

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
}

void print(){
    node* curr = start;
    while(curr != NULL){
        cout<<curr->number<<"\t";
        curr = curr->next;
    }
}

void position(int element){
    int count = 1;
    node* curr = start;
    while(curr != NULL){
        if(curr->number == element){
            cout<< "the position is: "<< count; 
            break;
        }
        count++;
        curr = curr->next;
    }
    if(curr == NULL){
        cout<<"Element does not exist.";
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
    cout<<endl<<"Enter the element you want to know its position: ";
    cin>>e;
    position(e);
    return 0;
}
