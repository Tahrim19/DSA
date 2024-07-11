#include <iostream>
#include <fstream>


struct node{
	int number;
	node* next;
	node* prev;
	//node* cursor;
};
node* start = nullptr;

struct stack{
	int popped_number;
};
stack* top = nullptr;

// Function to insert a node in the linked list.
void Insert() {
    node* temp = new node();
    std::cout << "Enter number: ";
    std::cin >> temp->number;

    if (start == nullptr) {
        start = temp;
    } else {
        node* curr = start;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
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


//// Function to move the cursor forward by a specified number of steps.
//int MoveForward(int steps) {
//    // Check if the linked list is empty.
//    if (!start) {
//        std::cout << "List empty." << std::endl;
//        return -1;
//    }
//
//    node* cursor = start; // Initialize the cursor at the start of the list.
//    int index = 0; // Initialize the index to 0.
//
//    for (int i = 0; i < steps; i++) {
//        // Check if the cursor has a next node to move to.
//        if (cursor->next) {
//            cursor = cursor->next; // Move the cursor to the next node.
//            index++; // Update the index to reflect the new position.
//        } else {
//            // If the end of the list is reached before completing 'steps', print a message.
//            std::cout << "Reached the end of the list." << std::endl;
//            return index;
//        }
//    }
//
//    // Successfully moved the cursor forward by the specified number of steps.
//    std::cout << "Cursor moved forward by " << steps << " steps." << std::endl;
//    std::cout << "Cursor is now at index " << index << " of the list." << std::endl;
//    std::cout << "Value at index " << index << ": " << cursor->number << std::endl;
//    return index;
//}




//// Function to move the cursor backward by a specified number of steps.
//int MoveBackward(int steps) {
//    // Check if linked list is empty.
//    if (!start) {
//        std::cout << "List empty." << std::endl;
//        return -1;
//    }
//
//    // Initialize cursor and previous node pointers.
//    node* curr = start;     // Pointer to the current node (cursor).
//    node* prev = nullptr;     // Pointer to the previous node.
//    int count = 0;            // Counter to keep track of the total number of nodes.
//    int current_index = 0;    // Initialize the current index.
//
//    // Calculate the total number of nodes and find the current index.
//    while (curr != nullptr) {
//        count++;               // Increment the count to count nodes.
//        prev = curr;         // Update 'prev' to the current node.
//        curr = curr->next; // Move 'cursor' to the next node.
//        current_index++;       // Increment the current index.
//    }
//
//    // Reset 'cursor' to the start of the linked list.
//    curr = start;
//
//    // Calculate the new position for the cursor.
//    int target_position = current_index - steps;
//
//    // Check if the list is empty or if the steps are out of bounds.
//    if (!curr || target_position < 0 || steps > count) {
//        std::cout << "Steps out of bounds." << std::endl;
//        return -1;
//    } 
//
//    // Move the cursor to the new position.
//    for (int i = 1; i <= target_position; i++) {
//        prev = curr;         // Update 'prev' to the current node.
//        curr = curr->next; // Move 'cursor' to the next node.
//    }
//    
//    // Provide information about the cursor's movement.
//    std::cout << "Cursor moved backward by " << steps << " steps." << std::endl;
//    std::cout << "Cursor is now at index " << current_index - steps << " of the list." << std::endl;
//
//    // Print the number associated with the current index.
//    std::cout << "Value at index " << current_index - steps << ": " << curr->number << std::endl;
//    return target_position;
//}


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

	int steps;
	std::cout<<"Enter the number of steps you want the cursor to move:";
	std::cin>>steps;
	
//	MoveForward(steps);
	int cursor_position = MoveBackward(steps);
//	int step;
//	std::cout<<"Enter the number of steps you want the cursor to move forward:";
//	std::cin>>step;
//	int cursor_position = MoveForward(step);
	
//	
//	std::cout<<"deleting the node where the cursor is present."<<std::endl;
//	DeleteImmediate(cursor_position);
	
//	int addNum;
//	std::cout<<"Enter the number of you want to add at the current cursor position:";
//	std::cin>>addNum;
//	AddImmediate(addNum,a);
	

//	PrintCursorData(cursor_position);
//	int index , num;
//	std::cout<<"enter the index number at which u want to update the data:";
//	std::cin>>index;
//	int num;
//	std::cout<<"enter the number wich will go on the replaced data:";
//	std::cin>>num;
//	UpdateIndexNumber(index , num);
//	int cursor_position;
//	if(cursor_position == false){
//		UpdateCursorNumber(cursor_position,num);
//	}
//	else{
//		UpdateCursorNumber(-1,num); // -1 means cursor is at lists null
//	}
	
	int index;
	std::cout<<"enter the index";
	std::cin>>index;
	Shift(cursor_position,index);
	print();
	
//	int cursor_position;
//	if(cursor_position == false){
//		Shift(cursor_position,index);
//	}
//	else{
//		Shift(-1,index); // -1 means cursor is at lists null
//	}
//	print();
	
	return 0;
}
