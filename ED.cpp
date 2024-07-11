#include <iostream>
#include <fstream>

struct node{
	int number;
	node* next;
	node* prev;
	//node* cursor;
};
node* start = nullptr;

// Function to insert a node in the linked list.
void Insert() {
    // Create a new node and allocate memory for it.
    node* temp = new node();

    // Prompt the user to enter a number and store it in the new node's data.
    std::cout << "Enter number: ";
    std::cin >> temp->number;

    // Check if the linked list is empty.
    if (start == nullptr) {
        // If it's empty, set the 'start' pointer to the new node.
        start = temp;
    } else {
        // If the list is not empty, traverse to the end of the list.
        node* curr = start;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        // Add the new node to the end of the list.
        curr->next = temp;
    }
    return;
}

void print(){
	node* curr = start;
	while(curr != NULL){
		std::cout << curr->number;
		std::cout << " -> ";
		curr = curr->next;
	}
	std::cout << "null";
}



// Function to delete the last node from the list
void DeleteLast() {
    // Check if the linked list is empty (start is nullptr).
    if (!start) {
        return; 
    }

    // Check if there is only one node in the list.
    if (!start->next) {
        delete start;  // Delete the single node
        start = nullptr;  // Set the 'start' pointer to nullptr to indicate an empty list.
        return;
    }
    node* curr = start;   // If there are multiple nodes, traverse the list to find the second-to-last node.
 
    // Traverse the list until the second-to-last node (where 'next' of next is nullptr).
    while (curr->next->next != nullptr) {
        curr = curr->next;
    }
    delete curr->next;   // Delete the last node (which is currently pointed to by 'curr->next').
    curr->next = nullptr;  // Set the 'next' pointer of the second-to-last node to nullptr
	
	return;
}

// Function to delete a node at a specific index in the linked list.
void DeleteAtSpecificIndex(int SearchIndex) {
    int index = 0;      // Initialize index to 0.
    node* curr = start; // Initialize the current node to the start of the list.
    node* prev = nullptr; // Initialize the previous node pointer to nullptr.

    // Traverse the list until the specified index or the end of the list is reached.
    while (curr != nullptr && index < SearchIndex) {
        prev = curr;    // Update the previous node pointer to the current node.
        curr = curr->next; // Move the current node to the next node in the list.
        index++;        // Increment the index.
    }

    // Check if the index is valid (within the bounds of the list).
    if (index == SearchIndex) {
        // Found the node at the specified index.

        // If the node to delete is the first node (index == 0).
        if (index == 0) {
            start = curr->next; // Update 'start' to skip the first node.
        } else {
            prev->next = curr->next; // Update the previous node's 'next' pointer to skip the current node.
        }

        delete curr; // Delete the current node.
    } 
    else {
        // Index is out of bounds.
        std::cout << "Index out of bounds." << std::endl;
    }
}


// Function to add a node at a specific index in the linked list.
void AddAtSpecificIndex(int SearchIndex) {
    int index = 0;      // Initialize index to 0.
    node* curr = start; // Initialize the current node to the start of the list.
    node* prev = nullptr; // Initialize the previous node pointer to nullptr.

    // Traverse the list until the specified index or the end of the list is reached.
    while (curr != nullptr && index < SearchIndex) {
        prev = curr;    // Update the previous node pointer to the current node.
        curr = curr->next; // Move the current node to the next node in the list.
        index++;        // Increment the index.
    }

    // Check if the index is valid (within the bounds of the list).
    if (index == SearchIndex) {
        // Found the position to insert the new node.

        // Create a new node and input its data.
        node* temp = new node();
        std::cout << "Enter the number to be inserted at index " << SearchIndex << ": ";
        std::cin >> temp->number;

        if (index == 0) {
            // If inserting at the beginning (index == 0), update 'start' to point to the new node.
            temp->next = start;
            start = temp;
        } else {
            // Insert the new node between 'prev' and 'curr'.
            prev->next = temp;
            temp->next = curr;
        }
    } else {
        // Index is out of bounds.
        std::cout << "Index out of bounds." << std::endl;
    }
}


// Function to move the cursor forward by a specified number of steps.
void MoveForward(int steps) {
    // Check if the linked list is empty.
    if (!start) {
        std::cout << "List empty." << std::endl;
        return;
    }

    node* cursor = start; // Initialize the cursor at the start of the list.

    for (int i = 0; i < steps; i++) {
        // Check if the cursor has a next node to move to.
        if (cursor->next) {
            cursor = cursor->next; // Move the cursor to the next node.
        } else {
            // If the end of the list is reached before completing 'steps', print a message.
            std::cout << "Reached the end of the list." << std::endl;
            return;
        }
    }

    // Successfully moved the cursor forward by the specified number of steps.
    std::cout << "Cursor moved forward by " << steps << " steps." << std::endl;
}


// Function to move the cursor backward by a specified number of steps.
int MoveBackward(int steps) {
    // Check if linked list is empty.
    if (!start) {
        std::cout << "List empty." << std::endl;
        return -1;
    }

    // Initialize cursor and previous node pointers.
    node* curr = start;     // Pointer to the current node (cursor).
    node* prev = nullptr;     // Pointer to the previous node.
    int count = 0;            // Counter to keep track of the total number of nodes.
    int current_index = 0;    // Initialize the current index.

    // Calculate the total number of nodes and find the current index.
    while (curr != nullptr) {
        count++;               // Increment the count to count nodes.
        prev = curr;         // Update 'prev' to the current node.
        curr = curr->next; // Move 'cursor' to the next node.
        current_index++;       // Increment the current index.
    }

    // Reset 'cursor' to the start of the linked list.
    curr = start;

    // Calculate the new position for the cursor.
    int target_position = current_index - steps;

    // Check if the list is empty or if the steps are out of bounds.
    if (!curr || target_position < 0 || steps > count) {
        std::cout << "Steps out of bounds." << std::endl;
        return -1;
    } 

    // Move the cursor to the new position.
    for (int i = 1; i <= target_position; i++) {
        prev = curr;         // Update 'prev' to the current node.
        curr = curr->next; // Move 'cursor' to the next node.
    }
    
    // Provide information about the cursor's movement.
    std::cout << "Cursor moved backward by " << steps << " steps." << std::endl;
    std::cout << "Cursor is now at index " << current_index - steps << " of the list." << std::endl;

    // Print the number associated with the current index.
    std::cout << "Value at index " << current_index - steps << ": " << curr->number << std::endl;
    return target_position;
}


// Function to add a node to the current cursor position.
void AddImmediate(int addNum, int cursor_position) {
    // Check if the list is empty.
    if (!start) {
        std::cout << "List is empty." << std::endl;
        return; // Exit the function if the list is empty.
    }

    // Create a new node and allocate memory for it.
    node* addnew = new node();
    addnew->number = addNum; // Set the data for the new node.

    if (cursor_position == 0) { // Check if 'a' is 0 (insertion at the beginning).
        addnew->next = start; // Update the new node's next pointer to the current start node.
        start = addnew; // Update the start pointer to point to the new node.
        print();
        return; // Exit the function since the insertion is done.
    }

    node* curr = start; // Initialize 'curr' to the start of the list.
    node* prev = nullptr; // Initialize 'prev' to nullptr (no previous node yet).
    int count = 0; // Initialize a counter to keep track of the current index.

    while (curr != nullptr && count < cursor_position) {
        prev = curr; // Update 'prev' to the current node.
        curr = curr->next; // Move 'curr' to the next node.
        count++; // Increment the counter to track the current index.
    }

    // Check if 'cursor_position' is out of bounds.
    if (count < cursor_position) {
        std::cout << "Index out of bounds." << std::endl;
        print(); // Print the list to provide context.
        return; // Exit the function since the insertion is not possible.
    }

    // Insert the new node between 'prev' and 'curr'.
    prev->next = addnew; // Update the 'next' pointer of 'prev' to point to the new node.
    addnew->next = curr; // Update the 'next' pointer of the new node to point to 'curr'.
}

// Function to delete the node where the current cursor position is.
void DeleteImmediate(int cursor_position) {
    // Handle the empty list case.
    if (!start) {
        std::cout << "The list is empty." << std::endl;
        return; // Exit the function if the list is empty.
    }

    // Handle the deletion of the first node of the list.
    if (cursor_position == 0) {
        node* temp = start;
        start = start->next; // Update 'start' to point to the second node.
        delete temp; // Delete the first node.
        print(); // Print the updated list.
        return; // Exit the function after successful deletion.
    }

    node* curr = start;
    node* prev = nullptr;
    int count = 0;
    bool deleted = false; // Initialize the 'deleted' flag to false.

    // Traverse the list to find the node at the specified cursor_position.
    while (curr != nullptr) {
        if (count == cursor_position) {
            prev->next = curr->next; // Update the 'next' pointer of the previous node.
            delete curr; // Delete the current node.
            deleted = true; // Set 'deleted' to true when a node is successfully deleted.
            return; // Exit the loop and the function after successful deletion.
        }
        prev = curr;
        curr = curr->next;
        count++;
    }

    // If the loop completes without finding the specified position, it's out of bounds.
    if (!deleted) {
        std::cout << "Index out of bounds." << std::endl;
    }
}

// Function to print the data at the current cursor position.
void PrintCursorData(int cursor_position) {
    // Handle empty list case.
    if (!start) {
        std::cout << "The list is empty." << std::endl;
        return; // Exit the function if the list is empty.
    }

    node* curr = start;
    int count = 0;
    
    // Traverse the list to find the node at the specified cursor_position.
    while (curr != NULL) {
        if (count == cursor_position) {
            std::cout << "The value at current cursor position is: " << curr->number << std::endl;
            return; // Exit the function after printing the value.
        }
        count++;
        curr = curr->next;
    }

    // If the loop completes without finding the specified position, it's out of bounds.
    if (count > cursor_position) {
        std::cout << "Index out of bounds." << std::endl;
    }
}

// Function to update index value
void UpdateIndexNumber(int index , int num){
	// handle the empty list case
	if(!start){
		std::cout<<"list is empty";
		return;
	}
	node* curr = start;
	bool updated = false;
	int count = 0;
	while(curr != NULL){
		if(count == index){
			curr->number = num;
			updated = true;
			return;
		}
		count++;
		curr = curr->next;
	}
	if(!updated){
		std::cout<<"index out of bounds."<<std::endl;
	}
} 

// Function to update the nodes value at current cursor position
void UpdateCursorNumber(int cursor_position , int num){
	// Handle the case of empty list
	if(!start){
		std::cout<<"the list is empty";
		return;
	}
	node* curr = start;
	bool updated = false;
	int count = 0;
	while(curr != NULL){
		if(cursor_position == NULL){
			std::cout<<"the cursor is pointing to NULL."<<std::endl;
			return;
		}
		else if(count == cursor_position){
			curr->number = num;
			updated = true;
			return;
		}
		count++;
		curr = curr ->next;
	}
	if(!updated){
		std::cout << "index out of bounds"<<std::endl;
	}
}

// Function to shift the data of the cursor with the data of the node at the specified index.
void Shift(int cursor_position, int index) {
    // Handle the empty list case
    if (!start) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    node* curr = start;
    node* cursor_node = nullptr;
    node* index_node = nullptr;

    int count = 0;
    while (curr != nullptr) {
        if (count == cursor_position) {
            cursor_node = curr;
        }
        if (count == index) {
            index_node = curr;
        }
        if (cursor_node && index_node) {
            break;  // Stop searching once both nodes are found.
        }
        curr = curr->next;
        count++;
    }

    // Check if both nodes were found.
    if (cursor_node && index_node) {
        // Swap the data values between the cursor node and the index node.
        int temp = cursor_node->number;
        cursor_node->number = index_node->number;
        index_node->number = temp;
        std::cout << "Data swapped." << std::endl;
    } else {
        std::cout << "Index out of bounds." << std::endl;
    }
}



int main(){
	Insert();
	Insert();
	Insert();
	Insert();
	Insert();

//	DeleteLast();
//	print();
	
//	int SearchIndex;
//	std::cout<<"enter the index:";
//	std::cin>>SearchIndex;
//	//DeleteAtSpecificIndex(SearchIndex);
//	
//	AddAtSpecificIndex(SearchIndex);
	
//	int steps;
//	std::cout<<"Enter the number of steps you want the cursor to move:";
//	std::cin>>steps;
	
	//MoveForward(steps);
//	int cursor_position = MoveBackward(steps);
		
//	int addNum;
//	std::cout<<"Enter the number of you want to add at the current cursor position:";
//	std::cin>>addNum;
//	AddImmediate(addNum , cursor_position);
//	print();

//	std::cout<<"deleting the node where the cursor is present."<<std::endl;
//	DeleteImmediate(cursor_position);
//	print();

//	PrintCursorData(cursor_position);
//	print();
	
//	int index , num;
//	std::cout<<"enter the index number at which u want to update the data:";
//	std::cin>>index;
//	std::cout<<"enter the number wich will go on the replaced data:";
//	std::cin>>num;
//	UpdateIndexNumber(index , num);
//	print();

//	int num;
//	std::cout<<"enter the number wich will go on the replaced data:";
//	std::cin>>num;
//	int cursor_position;
//	if(cursor_position == false){
//		UpdateCursorNumber(cursor_position,num);
//	}
//	else{
//		UpdateCursorNumber(-1,num); // -1 means cursor is at lists null
//	}


	int steps;
	std::cout<<"Enter the number of steps you want the cursor to move:";
	std::cin>>steps;
	int cursor_position = MoveBackward(steps);

	int index;
	std::cout<<"enter the index";
	std::cin>>index;
	Shift(cursor_position,index);
	print();

	
	
	return 0;
}
