/* QUESTION: A big integer is an integer whose digits are stored as elements in a data structure:

- Represent integers with one digit per node of a linked list.

- compute addition , subtraction, multiplication of two integers stored as a big integers the 
  resultant should also be stored as a big integer.  */
  
#include<iostream>
using namespace std;  

struct node{
	int number;
	node* next;
};
node* start = NULL; 


    // this will cause the digit to always be inserted in last. like num = 123 , output = 3 2 1 
//void insert(int value){
//	while( value > 0){
//		int digit = value % 10;
//		value = value / 10;
//		
//		node* temp = new node();
//		temp->number = digit;
//		temp->next = NULL;
//		if(start == NULL){
//			start = temp;
//		}
//		else{
//			node* curr = start;
//			while(curr->next != NULL){
//				curr = curr->next;
//			}
//			curr->next = temp;
//		}
//	}
//	
//}



// function which inserts each digit at the beginning of list.
void insert(int value) {
    while (value > 0) {
        int digit = value % 10;
        value = value / 10;

        node* temp = new node();
        temp->number = digit;
        temp->next = start;
        start = temp;
    }
}

// function to print list
void print(){
	node* curr = start;
	while(curr != NULL){
		cout<<curr->number<<"\t";
		curr = curr->next;
	}
}

// function which calculates the sum of each digit
int Addition(){
	int sum = 0;
	node* curr = start;
	while (curr != NULL){
		sum = sum + curr->number;
		curr = curr->next;
	}
	return sum;
}

// function which calculates the difference of each digit
int Subtraction(){
	int sub = start->number;
	node* curr = start;
	while (curr != NULL){
		sub = sub - curr->number;
		curr = curr->next;
	}
	return sub;
}

// function which calculates the product of each digit
int Multiplication(){
	int mul = start->number;
	node* curr = start;
	while (curr != NULL){
		mul = mul * curr->number;
		curr = curr->next;
	}
	return mul;
}

int main(){
	int value;
	cout<<"Enter the big integer: ";
	cin>>value;
	cout<<endl;
	
	cout<<"The list is: "<<endl;
	insert(value);
	print();
	cout<<endl;
	
	int res = Addition();
	cout<<endl<<"ADDITION: " << res << endl;
	
	int a = Subtraction();
	cout<<endl<<"SUBTRACTION: "<< a << endl;

	int b = Multiplication();
	cout<<endl<<"MULTIPLICATION: "<< b << endl;

	return 0;
}

