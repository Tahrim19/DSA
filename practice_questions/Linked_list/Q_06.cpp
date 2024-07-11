/* 6. Write a C++ program to find the middle element of a given Linked List.
Test Data:
Original list:
7 5 3 1
Middle element of the said list:
3
Original list:
9 7 5 3 1
Middle element of the said list:
5
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
void count(){
    int ct = 0;
    node* curr = start;
    cout<<"Original list:"<<endl;
    while(curr != NULL){
        ct++;
        cout<<curr->number<<"\t";
        curr = curr->next;
    }
    if(ct%2==0){
        int pos = ct / 2;
        curr = start;
        int i = 0;
        while (i < pos) {
            curr = curr->next;
            i++;
        }
    cout << endl << "The middle element is: " << curr->number;
    }
    else{
        int pos = ct / 2;
        curr = start;
        int i = 1;
        while (i <= pos) {
            curr = curr->next;
            i++;
        }
    cout << endl << "The middle element is: " << curr->number;
    }



    
}
int main() {
    insert(13);
    insert(11);
    insert(9);
    insert(7);
    insert(5);
    insert(3);
    insert(1);
    count();
    return 0;
}
