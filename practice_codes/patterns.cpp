#include <iostream>
using namespace std;

void Rectangle(int r , int c){
        for(int i = r; i > 0; i--){
        for(int j = c; j > 0; j--){
            cout<<"* ";
        }
        cout << endl;
    }
}

void HollowRectangle(int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (i == 0 || i == r - 1 || j == 0 || j == c - 1) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl; 
    }
}

void InvertedHalfPyaramid(int n){
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void HalfPyramid(int n){
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(j <= n-i){
                cout << "  ";
            }
            else{
            cout << "* ";
            }
        }
        cout << endl;
    }
}

void HalfPyramidNumbers(int n){
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cout << i << " ";
        }
        cout << endl;
    }
}

void FloydsTriangle(int n){
    int count = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cout << count << " ";
            count++;
        }
        cout << endl;
    }
}

void Butterfly(int n) {
    // Upper part of the butterfly
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        int space = 2 * (n - i);
        for (int j = 1; j <= space; j++) {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    // Lower part of the butterfly
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        int space = 2 * (n - i);
        for (int j = 1; j <= space; j++) {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

int main() {
    int r = 5, c = 4, n = 5;

    cout << "RECTANGLE: \n";
    Rectangle(r , c);
    cout << endl;

    cout << "HOLLOW RECTANGLE: \n";
    HollowRectangle(r, c);
    cout << endl;

    cout << "INVERTED HALF PYRAMID: \n";
    InvertedHalfPyaramid(n);
    cout << endl;

    cout << "HALF PYRAMID: \n";    
    HalfPyramid(n);
    cout << endl;
    
    cout << "HALF PYRAMID NUMBERS: \n";    
    HalfPyramidNumbers(n);
    cout << endl;
    
    cout << "FLOYD'S TRIANGLE: \n";    
    FloydsTriangle(n);
    cout << endl;
    
    cout << "BUTTERFLY PATTERN: \n";    
    Butterfly(n);
    cout << endl;

    return 0;
}


