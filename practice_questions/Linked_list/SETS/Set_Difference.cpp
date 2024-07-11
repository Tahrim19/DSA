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

bool comparision(int element){
	list2* curr2 = start2;  // Initialize a pointer to the start of Set 2

	while(curr2 != NULL){  // Loop through elements in Set 2
		if(curr2->number == element){  // Check if the current element matches the input element
			return false;  // If a match is found, return false
		}
		curr2 = curr2->next;  // Move to the next element in Set 2
	}
	return true;  // If no match is found, return true
}

void difference(){
	list1* curr1 = start1;  // Initialize a pointer to the start of Set 1

	while(curr1 != NULL){  // Loop through elements in Set 1
		list2* curr2 = start2;  // Initialize a pointer to the start of Set 2

		while(curr2 != NULL){  // Loop through elements in Set 2
		
			if(comparision(curr1->number)){  // Call the comparision function to check if the element from Set 1 is in Set 2
				insert_list3(curr1->number);  // If the element is not in Set 2, insert it into Set 3
				break;  // Exit the inner loop to avoid adding the same element more than once
			}
			curr2 = curr2->next;  // Move to the next element in Set 2
		}
		curr1 = curr1->next;  // Move to the next element in Set 1
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
	
	difference();
	cout<<"DIFFERENCE:\t";
	print_list3();
	
	return 0;
}

