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

void print_list3(){
	list3* curr = start3;
	while(curr != NULL){
		cout<<curr->number<<"\t";
		curr = curr->next;
	}
}


// Function to merge elements of two sets (list1 and list2) into a new set (list3)
list3* Union(list1* L1, list2* L2) {
    list1* curr1 = start1; // Initialize a pointer to the start of list1
    list2* curr2 = start2; // Initialize a pointer to the start of list2

    // Iterate through list1 and copy its elements to list3
    while (curr1 != NULL) {
        insert_list3(curr1->number); // Insert the current element from list1 into list3
        curr1 = curr1->next; // Move to the next element in list1
    }

    // Iterate through list2 and copy its elements to list3
    while (curr2 != NULL) {
        int value = curr2->number; // Get the value from the current element in list2
        bool duplicate = false; // Flag to check for duplicate elements

        // Iterate through list3 to check for duplicates
        list3* curr3 = start3;
        while (curr3 != NULL) {
            if (curr3->number == value) {
                duplicate = true; // Found a duplicate element
                break; // No need to continue checking
            }
            curr3 = curr3->next; // Move to the next element in list3
        }

        if (!duplicate) {
            insert_list3(value); // Insert the non-duplicate element into list3
        }
        curr2 = curr2->next; // Move to the next element in list2
    }

    return start3; // Return the merged list (list3)
}


// It takes a double pointer to 'list3' (list3** a) and a pointer to 'list2' (list2* start2).
// The double pointer allows modifications to the 'list3' reference within the function.

void complement(list3** a, list2* start2) {
    list3* curr3 = *a;  // Initialize curr3 to the start of list3

    while (curr3 != NULL) {  // Iterate through list3
        list2* curr2 = start2;
        bool found = false;  // Flag to track if a match is found

        while (curr2 != NULL) {  // Iterate through list2
            if (curr2->number == curr3->number) {  // Check for a match
                found = true;  // Match found
                break;  // Exit the inner loop since we don't need to check further in list2
            }
            curr2 = curr2->next;  // Move to the next element in list2
        }

        // If a match was found, remove the element from list3
        if (found) {
            list3* toRemove = curr3;  // Store the current node to be removed
            curr3 = curr3->next;  // Move to the next node in list3 before deleting

            if (toRemove->prev == NULL) {
                // If it's the first element in list3
                *a = toRemove->next;  // Update the start of list3
                if (*a != NULL) {
                    (*a)->prev = NULL;  // Update the prev pointer of the new first element
                }
            } else {
                // It's a middle or last element in list3
                toRemove->prev->next = toRemove->next;  // Update next pointer of the previous node
                if (toRemove->next != NULL) {
                    toRemove->next->prev = toRemove->prev;  // Update prev pointer of the next node
                }
            }

            delete toRemove;  // Use the 'delete' operator to deallocate memory
        } else {
            curr3 = curr3->next;  // Move to the next node in list3
        }
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
	list3* a = Union(start1 , start2);
	cout<<endl<<"COMPLMNENT:\t";
	complement(&start3,start2);
	print_list3();

	return 0;
}


