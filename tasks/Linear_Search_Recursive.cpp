#include <iostream>
using namespace std;

int linearSearchRecursive(int arr[], int startIndex, int endIndex, int target) {
    if (startIndex > endIndex) {
        return -1; // Target not found
    }
    
    if (arr[startIndex] == target) {
        return startIndex; // Found the target at the current index
    }
    
    return linearSearchRecursive(arr, startIndex + 1, endIndex, target); // Recursive call for the next index
}

int main() {
    int len;
    cout << "Enter the length of the array: ";
    cin >> len;
    
    cout<<"enter elements of array: "<<endl;
    int arr[len];
    for (int i = 0; i < len; i++) {
        //cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }
    
    int number;
    cout << "Enter the number to be searched: ";
    cin >> number;

    int result = linearSearchRecursive(arr, 0, len - 1, number);

    if (result != -1) {
        cout << "Element found at index " << result+1 << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}

