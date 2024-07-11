#include <iostream>
using namespace std;

struct student {
    int id;
    int marks;
    float gpa;
};
// Linear search function.
int linearSearch(const student students[], int n, int targetId) {
    for (int i = 0; i < n; ++i) {
        if (students[i].id == targetId) {
            return i; // Return index if ID is found
        }
    }
    return -1; // Return -1 if ID is not found
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    student students[n]; // Create an array of student type

    // Inputting students data.
	for (int i = 0; i < n; ++i) {
        cout << "Enter information for student " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> students[i].id;
        cout << "Marks: ";
        cin >> students[i].marks;
        cout << "GPA: ";
        cin >> students[i].gpa;
        cout << "\n";
    }
    
    // Print the information of all students
    cout << "Student Information:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Student " << i + 1 << ":\n";
        cout << "ID: " << students[i].id << "\n";
        cout << "Marks: " << students[i].marks << "\n";
        cout << "GPA: " << students[i].gpa << "\n\n";
    }

    // Applying linear search using ID
	int targetId;
    cout << "Enter the ID to search: ";
    cin >> targetId;

    int index = linearSearch(students, n, targetId);

    if (index != -1) {
        cout << "Student with ID " << targetId << " found at index " << index << endl;
        cout << "Student Information:\n";
        cout << "ID: " << students[index].id << "\n";
        cout << "Marks: " << students[index].marks << "\n";
        cout << "GPA: " << students[index].gpa << "\n";
    } else {
        cout << "Student with ID " << targetId << " not found." << endl;
    }

    return 0;
}


