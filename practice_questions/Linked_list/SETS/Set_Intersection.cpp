#include <iostream>
#include <algorithm>
using namespace std;
struct list1{
	int number;
	list1* next;
	list1* prev;
};
list1* start1 = NULL;

struct list2{
	int number;
	list2* next;
	list2* prev;
};
list2* start2 = NULL;

struct list3{
	int number;
	list3* next;
	list3* prev;
};
list3* start3 = NULL;

// function to insert set 1
void insert_list1(int value){
	list1* temp = new list1();
	temp->number = value;
	temp->next = NULL;
	if(start1 == NULL){
		start1 = temp;
	}
	else{
		list1* curr = start1;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = temp;
		temp->prev = curr;
	}
}

// function to print set 1
void print_list1(){
	list1* curr = start1;
	while(curr != NULL){
		cout<<curr->number<<"\t";
		curr = curr->next;
	}
}

// function to insert set 2
void insert_list2(int value){
	list2* temp = new list2();
	temp->number = value;
	temp->next = NULL;
	if(start2 == NULL){
		start2 = temp;
	}
	else{
		list2* curr = start2;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = temp;
		temp->prev = curr;
	}
}

// function to print set 2
void print_list2(){
	list2* curr = start2;
	while(curr != NULL){
		cout<<curr->number<<"\t";
		curr = curr->next;
	}
}

void insert_list3(int value){
	list3* temp = new list3();
	temp->number = value;
	temp->next = NULL;
	if(start3 == NULL){
		start3 = temp;
	}
	else{
		list3* curr = start3;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = temp;
		temp->prev = curr;
	}
}

// function to print set 3
void print_list3(){
	list3* curr = start3;
	while(curr != NULL){
		cout<<curr->number<<"\t";
		curr = curr->next;
	}
}


void intersection() {
    list1* curr1 = start1;  // Initialize a pointer to the start of list1
    
    while (curr1 != NULL) {  // Loop through elements in list1
        list2* curr2 = start2;  // Initialize a pointer to the start of list2
        
        while (curr2 != NULL) {  // Loop through elements in list2
            if (curr1->number == curr2->number) {
            	
                // If a matching element is found in both list1 and list2, insert it into list3
                insert_list3(curr1->number);
            }
            curr2 = curr2->next;  // Move to the next element in list2
        }
        curr1 = curr1->next;  // Move to the next element in list1
    }
}


int main(){
	insert_list1(1);
	insert_list1(3);
	insert_list1(4);
	insert_list1(7);
	insert_list1(12);
	cout<<"SET 1:\t";
	print_list1();
	cout<<endl;
	
	insert_list2(1);
	insert_list2(5);
	insert_list2(7);
	insert_list2(9);
	cout<<"SET 2:\t";
	print_list2();
	cout<<endl;
	

	cout<<"INTERSECTION:\t";
	intersection();

	print_list3();

	return 0;
}
