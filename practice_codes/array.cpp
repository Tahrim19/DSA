#include <iostream>
#include <algorithm>
using namespace std;

// SEARCHING: 

void linear(int arr[], int size, int key){
    for(int i = 0 ; i<size; i++){
        if(arr[i] == key){
            cout<<"Found at index " << arr[i];
            return;
        }
    }
    cout<<"Not found!";
}

void binary(int arr[] , int size , int key){
    int left = 0;
    int right = size - 1;

    while(left<=right){
        int mid = (left + right)/2;
        if(arr[mid] == key){
            cout<<"Found at " << mid;
            return;
        }
        else if (arr[mid] < key){
            left = mid + 1; 
        }
        else{
            right = mid - 1;    
        }
    }
    cout<<"Not Found!";
}

// SORTING

void print(int arr[] , int size){
    for(int i=0; i<size; i++){
        cout<< arr[i] << " ";
    }

}



int main(){
    // int n , key;
    // cout<<"Enter the size of array: ";
    // cin>> n;
    
    // int arr[n];
    // cout<<"Enter the elements of array: ";
    // for(int i=0; i<n; i++){
    //     cin>>arr[i];
    // }

    // cout<<"Enter the element to be searched: ";
    // cin>>key;

    // linear(arr, n, key);
    // print(arr , n);
    // cout<<endl;
    // sort(arr , arr + n);
    // print(arr , n);
    // cout<<endl;
    // binary(arr,n,key);

    int array[10] = {23,56,89,34,12,77,34,90,57,61};
    // int n = sizeof(array) / sizeof(array[0]);
    // print(array , n);

    return 0;
}