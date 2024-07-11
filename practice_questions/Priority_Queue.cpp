/* QUESTION:
 You need to implement priority queue by choosing the appropriate data structure. 
 You need to take input the name of the task and its priority from the user to store in the queue. whenever a task is removed 
 from the queue the next highest priority task task will be placed in front. If two tasks with same prority enter then the first entered process
 is removed first  */
 
 #include <iostream>
using namespace std;

struct PriorityQueue{
	string taskName;
	int priority;
	PriorityQueue* next;
};
PriorityQueue* start = NULL;

// same code but iss mai comments nhi hain.

//void Insert(string taskName , int pr){
//	// create new node
//	PriorityQueue* temp = new PriorityQueue();
//	temp->taskName = taskName;
//	temp->priority = pr;
//	temp->next = NULL;
//	
//	
//	if(start == NULL || pr > start->priority){
//		temp->next = start;
//		start = temp;
//	}
//	
//	else if(pr == start->priority){
//		temp->next = start->next;
//		start->next = temp;
//	}
//	
//	else{
//		PriorityQueue* curr = start;
//		while(curr->next != NULL && pr < curr->next->priority){
//			curr = curr->next;
//		}
//		temp->next = curr->next;
//		curr->next = temp;
//	}
//}



// Function to insert a task with a given priority into the priority queue
void Insert(string taskName, int pr) {
    // Create a new node for the task 
    PriorityQueue* temp = new PriorityQueue();
    temp->taskName = taskName;
    temp->priority = pr;
    temp->next = NULL;  

    // If the linked list is empty or the new task has higher priority than the current head
    if (start == NULL || pr > start->priority) {
        temp->next = start;  // Set the new node's next pointer to the current head
        start = temp;  // Update the head to the new node
    }
    // If the new task has the same priority as the current head
    else if (pr == start->priority) {
        temp->next = start->next;  // Insert the new node immediately after the current head
        start->next = temp;  // Update the current head's next pointer to the new node
    }
    // If the new task has lower priority than the current head, find its correct position
    else {
        PriorityQueue* curr = start;
        while (curr->next != NULL && pr < curr->next->priority) {
            curr = curr->next;  // Traverse the linked list to find the appropriate position
        }
        temp->next = curr->next;  // Set the new node's next pointer to the next node of the current node
        curr->next = temp;  // Update the current node's next pointer to the new node
    }
}



void DisplayQueue(){
	PriorityQueue* curr = start;
	while(curr != NULL){
		cout<< curr->taskName << " , " << curr->priority <<endl;
		curr = curr->next;
	}
}


void Remove(){
	if(start == NULL){
		cout<<"Queue is empty";
	}
	PriorityQueue* temp = start;
	start = start->next;
	delete(temp);
}

int main() {
	Insert("Task1" , 3);
    Insert("Task2" , 2);
    Insert("Task3" , 1);
    Insert("Task4" , 2);
    Insert("Task5" , 0);
    Insert("Task6" , 1);
    Insert("Task7" , 0);
    Insert("Task8" , 8);
    DisplayQueue();
    cout<<endl<<endl;
    Remove();
    Remove();
    DisplayQueue();
    return 0;
}

