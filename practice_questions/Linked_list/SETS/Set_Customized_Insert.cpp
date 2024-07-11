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


void InsertSpecific(int data, int index){
	list2* temp = new list2();
	temp->number = data;
	temp->next = NULL;
	
	list2* curr2 = start2;
	int size = 0;
	while(curr2 != NULL){
		if(size == index){
			temp->next = curr2->next;
			curr2->next = temp;
			break;
		}
		size++;
		curr2 = curr2->next;
	}
}

void CustomInsert(int value, int element){
	list1* curr1 = start1;
	while(curr1 != NULL){   // copied list1 into list2
		insert_list2(curr1->number);
		curr1 = curr1->next;
	}
	
	list2* curr2 = start2;
	int index = 0;
	while(curr2 != NULL){ // inserting new node after every occurence of certain number
		if(curr2->number == value){
			InsertSpecific(element,index);
		}
		index++;
		curr2 = curr2->next;
	}
}


int main(){
	insert_list1(2);
	insert_list1(4);
	insert_list1(3);
	insert_list1(2);
	insert_list1(8);
	insert_list1(2);
	insert_list1(5);
	insert_list1(1);
	insert_list1(2);

	cout<<"SET :\t"<<endl;
	print_list1();
	cout<<endl;
	
	cout<<endl<<"CUSTOMIZING:"<<endl;
	CustomInsert(2,10);
	print_list2();

	
	return 0;
}
