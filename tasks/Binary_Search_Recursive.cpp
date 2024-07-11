#include <iostream>
#include <algorithm> // Include the <algorithm> header for the 'sort' function
using namespace std;

int binarySearch(int arr[], int low, int high, int number) { // Added low and high parameters
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == number) {
            return mid;
        } else if (arr[mid] < number) {
            return binarySearch(arr, mid + 1, high, number);
        } else {
            return binarySearch(arr, low, mid - 1, number);
        }
    }
    return -1; // Return -1 if not found
}    

int main() {
    int number;

    int len;
    cout << "Enter the length of array: ";
    cin >> len;

    int arr[len];
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + len); 

    // Print the sorted array
    for (int i = 0; i < len; i++) {
        cout << arr[i];
        if (i < len - 1)
            cout << ",";
    }
    cout << endl;
    
    cout << "Enter the number to be searched: ";
    cin >> number;

    int result = binarySearch(arr, 0, len - 1, number); // Added low and high values

    if (result != -1) {
        cout << "Element found at index " << result+1 << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}
