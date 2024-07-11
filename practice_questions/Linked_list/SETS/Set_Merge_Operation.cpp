#include <iostream>
#include <list>
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

void print_list3(){
	list3* curr = start3;
	while(curr != NULL){
		cout<<curr->number<<"\t";
		curr = curr->next;
	}
}

// Function to sort elements in list3 using the Bubble Sort algorithm
void sort_list3() {
    list3* curr3 = start3; // Initialize a pointer to the start of list3
    list3* nextNode;

    int swapped, temp;

    // Perform the Bubble Sort algorithm
    do {
        swapped = 0;
        curr3 = start3;

        while (curr3->next != NULL) {
            nextNode = curr3->next;

            // Compare adjacent elements and swap them if they are in the wrong order
            if (curr3->number > nextNode->number) {
                temp = curr3->number;
                curr3->number = nextNode->number;
                nextNode->number = temp;
                swapped = 1; // Flag to indicate that a swap occurred
            }
            curr3 = curr3->next; // Move to the next element in list3
        }
    } while (swapped); // Continue sorting until no more swaps are needed
}


void Merge(){
	list1* curr1 = start1;
	while(curr1 != NULL){
		insert_list3(curr1->number);
		curr1 = curr1->next;
	}
	
	list2* curr2 = start2;
	while(curr2 != NULL){
		insert_list3(curr2->number);
		curr2 = curr2->next;
	}
}


int main(){
	insert_list1(2);
	insert_list1(3);
	insert_list1(4);
	insert_list1(8);
	insert_list1(12);
	cout<<"SET 1:\t";
	print_list1();
	cout<<endl;
	
	insert_list2(1);
	insert_list2(4);
	insert_list2(5);
	insert_list2(7);
	insert_list2(9);
	cout<<"SET 2:\t";
	print_list2();
	
	cout<<endl<<"MERGE:\t";
	Merge();
	print_list3();
	cout<<endl;
	
	cout<<"sorted: "<<endl;
	sort_list3();
	print_list3();
	
	return 0;
}
