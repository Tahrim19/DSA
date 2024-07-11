#include <iostream>
#include <cstdlib>

// Define a structure for courses
struct course {
    int courseNo;          // Course number
    course* next;          // Pointer to the next course
    course* course_prev;
    struct student* student_start; // Pointer to the list of students in this course
};

// Initialize the start of the course list
course* course_start = nullptr;

// Define a structure for students
struct student {
    int studentID;         // Student ID
    int courseNo;          // Course number associated with the student
    student* nextStudent;  // Pointer to the next student in the same course
    student* student_prev;
    student* student_start;
};



// Function to insert a new course into the course list
void insert_NewCourse() {
    course* course_temp = new course(); // Create a new course node
    std::cout << "Enter the course number: ";
    std::cin >> course_temp->courseNo;       // Input course number
    course_temp->next = nullptr;
    course_temp->student_start = nullptr;      // Initialize the student list for this course

    course* course_curr = course_start;
    if (course_start == nullptr) {
        // If the course list is empty, set the new course as the start
        course_start = course_temp;
        return;
    } else {
        // Traverse the course list to find the end and add the new course
        while (course_curr->next != nullptr) {
            course_curr = course_curr->next;
        }
        course_curr->next = course_temp;
    }
}



// Function to insert a new student into a course
void insert_StudentToCourse() {
    student* student_temp = new student(); // Create a new student node
    std::cout << "Enter the Student ID: ";
    std::cin >> student_temp->studentID;         // Input student ID
    std::cout << "Enter the Course Number you want to be enrolled in: ";
    std::cin >> student_temp->courseNo;          // Input the course number for enrollment
    student_temp->nextStudent = nullptr;

    course* course_curr = course_start;
    while (course_curr != nullptr && course_curr->courseNo != student_temp->courseNo) {
        // Find the course in which the student wants to enroll
        course_curr = course_curr->next;
    }
    if (course_curr == nullptr) {
        // If the course is not found, display an error message
        std::cout << "Course not found!" << std::endl;
        delete student_temp; // Free memory for the student node
        return;
    }
    if (course_curr->student_start == nullptr) {
        // If no students are enrolled in the course, set the new student as the start
        course_curr->student_start = student_temp;
    } else {
        // Otherwise, find the end of the student list and add the new student
        student* student_curr = course_curr->student_start;
        while (student_curr->nextStudent != nullptr) {
            student_curr = student_curr->nextStudent;
        }
        student_curr->nextStudent = student_temp;
    }
}



// Function to print the list of students enrolled in each course and count the courses
void print_courses() {
    course* course_curr = course_start;   // Initialize a pointer to traverse the course list
    int courseCount = 0;      // Initialize a counter for courses
    // Iterate through the course list
    while (course_curr != nullptr) {
        std::cout << "Course " << course_curr->courseNo << " Students: "; // Print course number
        student* student_curr = course_curr->student_start; // Initialize a pointer to traverse the student list
        // Iterate through the student list of the current course
        while (student_curr != nullptr) {
            std::cout << student_curr->studentID << " "; // Print student ID
            student_curr = student_curr->nextStudent;     // Move to the next student
        }
        std::cout << std::endl; // Move to the next line after printing students of the current course
        course_curr = course_curr->next; // Move to the next course in the course list
        courseCount++;       // Increment the course count
    }
    std::cout << "Total Courses: " << courseCount << std::endl; // Print the total number of courses
}



// Function to delete a specific course from the course list
int deleteSpecificCourse(int toSearch) {
    course* course_curr = course_start;     // Initialize a pointer to traverse the course list
    course* course_prev = nullptr;      // Initialize a pointer to keep track of the previous course

    while (course_curr != nullptr) {     // Loop through the course list
        if (course_curr->courseNo == toSearch) {     // Check if the current course matches the course to be deleted
            if (course_prev == nullptr) {    // If the course to delete is the first course in the list
                course_start = course_curr->next;   // Update the start pointer to the next course
            } else {
                course_prev->next = course_curr->next;    // Update the previous course's next pointer to skip the current course
            }
            delete course_curr;   // Delete the current course to free memory
            std::cout << "The Course No. " << toSearch << " is deleted." << std::endl;
			return 1;       // Return 1 to indicate success
        }
        course_prev = course_curr;      // Update the previous course pointer
        course_curr = course_curr->next; // Move to the next course in the list
    }
    std::cout << "The Course No. " << toSearch << " was not found." << std::endl;
    return 0; // Return 0 if the course to delete was not found in the list
}



// Function to delete a specific student from a specific course.
int deleteStudent_FromCourse(int SearchID, int courseNo) {
    // Start by traversing the list of courses.
    course* course_curr = course_start;
    while (course_curr != nullptr) {
        // Check if the current course matches the specified course number.
        if (course_curr->courseNo == courseNo) {
            student* student_curr = course_curr->student_start;     // Initialize a pointer to traverse the list of students within the current course.
            student* student_prev = nullptr;    // A pointer to keep track of the previous student node.
            
            while (student_curr != nullptr) {     // Traverse the list of students within the current course.
                // Check if the current student's ID matches the specified SearchID.
                if (student_curr->studentID == SearchID) {  // If the student is found, perform the deletion.
                    if (student_prev == nullptr) {      // If the student to delete is the first in the course, update the course's start pointer
                        course_curr->student_start = student_curr->nextStudent;
                    } 
					else {
                        // If the student to delete is not the first in the course, update the previous student's next pointer.
                        student_prev->nextStudent = student_curr->nextStudent;
                    }  
                    
                    delete student_curr;   // Delete the student node to free up memory.
                    std::cout << "The student of ID " << SearchID << " is deleted from Course No. " << courseNo << std::endl;
					return 1;   // Indicate successful deletion.
                }
                // Move to the next student in the course.
                student_prev = student_curr;
                student_curr = student_curr->nextStudent;
            }
            std::cout << "Student with ID " << SearchID << " not found in Course No. " << courseNo << std::endl;
            return 0;
        }
        course_curr = course_curr->next;  // Move to the next course in the list.
    }
    std::cout << "Course No. " << courseNo << " not found." << std::endl;
    return 0;   // If the specified student was not found in any course, return 0 to indicate failure.
}



// Function to delete all the students from a specific course.
int deleteAllStudents_FromCourse(int SearchCourse) {
    course* course_curr = course_start;  // Start by traversing the list of courses
    while (course_curr != nullptr) {
        if (course_curr->courseNo == SearchCourse) {    // Check if the current course matches the specified SearchCourse.
            student* student_curr = course_curr->student_start;    // Initialize a pointer to traverse the list of students within the current course.
            while (student_curr != nullptr) {    // Iterate through the list of students in the current course.
                student* student_temp = student_curr;     // Store the current student node in student_temp.
                student_curr = student_curr->nextStudent;   // Move to the next student in the course.
                delete student_temp;    // Delete the student node stored in student_temp to free up memory.
            } 
            /*After deleting all students in the course, update the course's start pointer to nullptr
            to indicate that there are no students left in that course.*/
            course_curr->student_start = nullptr;
        }       
        course_curr = course_curr->next;  // Move to the next course in the list.
    }
    return 0;
}


int main() {
    int choice;
    std::string input;
    
    while(true){
    std::cout<<"Choose operation." << std::endl;
	std::cout<<"1. Insert Course." << std::endl;
	std::cout<<"2. Delete Course." << std::endl;
	std::cout<<"3. Add a student to a Course." << std::endl;
	std::cout<<"4. Delete a Student to a Course." << std::endl;
	std::cout<<"5. Delete a Student from every Course." << std::endl;
	std::cin>>choice;
	
	switch(choice){	
	case 1:
			insert_NewCourse();
			break;

		case 2:
			int toSearch;
			std::cout << "Enter the Course No. to be deleted.";
			std::cin >> toSearch;
			deleteSpecificCourse(toSearch);
			break;

		case 3:
			insert_StudentToCourse();
			break;
		
		case 4:
			int SearchID , courseNo;
			std::cout << "Enter the student ID to be Delete a Student to a Course. ";
			std::cin >> SearchID;
			
			std::cout << "Enter the Course No.: ";
			std::cin >> courseNo;
			
			deleteStudent_FromCourse(SearchID , courseNo);
			break;
		
		case 5:
			int SearchCourse;
			std::cout << "Enter the Course No. from which you want to delete the students.";
			std::cin >> SearchCourse;
			deleteAllStudents_FromCourse(SearchCourse);
			std::cout << "All the Students from the Course No. "<<SearchCourse<<" deleted."<< std::endl;
			break;
		
		default:
			std::cout << "You choose neither options." << std::endl;
			print_courses();
			break;
		}
		std::cout << "Do you want to continue? y/n: " << std::endl;
		std::cin >> input;
		if(input != "y"){
			std::cout<<" - - - - - - - - - - - - - - - - - - - - - -"<< std::endl;
			print_courses();
			break;
			exit(0);
			}
		}	
	return 0;
}

