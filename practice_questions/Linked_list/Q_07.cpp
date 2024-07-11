/* 7. Write a C++ program to insert a new node at the middle of a given Singly Linked List.
Test Data:
Original list:
7 5 3 1
Singly Linked List: after insert 9 in the middle of the said list-
7 5 9 3 1
Singly Linked List: after insert 11 in the middle of the said list-
7 5 9 11 3 1
Singly Linked List: after insert 13 in the middle of the said list-
7 5 9 13 11 3 1
*/
#include <iostream>
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


void insert_middle(int value) {
    int count = 0;
    node* curr = start;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }

    if (count % 2 == 1) {  // Check for an odd number of nodes
        int pos = count / 2;
        curr = start;
        int i = 0;

        while (i < pos) {
            curr = curr->next;
            i++;
        }

        // Now, 'curr' points to the node just before the middle node
        node* temp = new node();
        temp->number = value;
        temp->next = curr->next;
        curr->next = temp;
    }
    else{
    	int pos = count / 2;
        curr = start;
        int i = 1;

        while (i < pos) {
            curr = curr->next;
            i++;
        }

        // Now, 'curr' points to the node just before the middle node
        node* temp = new node();
        temp->number = value;
        temp->next = curr->next;
        curr->next = temp;
	}
}


int main() {
	int num,n;
	cout<<"Enter the elements of singly linked list:"<<endl;
	cin>>num;
	
	for(int i = 0; i<num; i++){
		cout<<"enter number:";
		cin>>n;
		insert(n);
	}
	cout<<"Original List:"<<endl;
    print();
    int value;
    cout << endl << "Enter a number to be inserted at the middle of the list: ";
    cin >> value;
    insert_middle(value);
    cout<<endl<<"The updated list is:"<<endl;
    print(); // print the updated list
    return 0;
}

