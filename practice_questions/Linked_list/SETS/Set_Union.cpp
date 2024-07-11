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

// function which checks if elemnt already exists in list 3. if not then inserts it.
void duplication(int element) {
    list3* curr3 = start3;  // Initialize a pointer to the start of list3

    while (curr3 != NULL) {  // Loop through elements in list3
        if (curr3->number == element) {
            // If the element already exists in list3, return without adding it again
            return;
        }
        curr3 = curr3->next;  // Move to the next element in list3
    }

    insert_list3(element);  // If the element is not found, insert it into list3
}


// function to perform union operation on set 1 and set 2
void Union() {
    list1* curr1 = start1;  // Initialize a pointer to the start of list1
    list2* curr2 = start2;  // Initialize a pointer to the start of list2

    while (curr1 != NULL) {  // Loop through elements in list1 and insert them into list3
        insert_list3(curr1->number);
        curr1 = curr1->next;  // Move to the next element in list1
    }

    while (curr2 != NULL) {  // Loop through elements in list2 and add them to list3, avoiding duplicates
        duplication(curr2->number);
        curr2 = curr2->next;  // Move to the next element in list2
    }
}

// Function to sort elements in list3 using the Bubble Sort algorithm
void sort_list3() {
    list3* curr = start3; // Initialize a pointer to the start of list3
    list3* nextNode;

    int swapped, temp;

    // Perform the Bubble Sort algorithm
    do {
        swapped = 0;
        curr = start3;

        while (curr->next != NULL) {
            nextNode = curr->next;

            // Compare adjacent elements and swap them if they are in the wrong order
            if (curr->number > nextNode->number) {
                temp = curr->number;
                curr->number = nextNode->number;
                nextNode->number = temp;
                swapped = 1; // Flag to indicate that a swap occurred
            }
            curr = curr->next; // Move to the next element in list3
        }
    } while (swapped); // Continue sorting until no more swaps are needed
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
	
	cout<<endl<<"UNION:\t";
	Union();
	sort_list3();
	print_list3();
	
	return 0;
}
