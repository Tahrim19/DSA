#include<iostream>
using namespace std;

int main() {
    int m = 3, n = 3, sum = 0;
    int a[3][3], b[3][3], res[3][3];

	cout << "Enter the first 3x3 matrix:\n";
	for (int i = 0; i < 3; i++) {
	    for (int j = 0; j < 3; j++) {
	        cout << "Enter the element at position " << i+1 << ", " << j+1 << ": ";
	        cin >> a[i][j];
	    }
	}
	cout << endl << "The First matrix is: "<<endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }


    cout << "Enter the second 3x3 matrix:\n";
    for (int i = 0; i <3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Enter the element at position " << i+1 << ", " << j+1 << ": ";
            cin >> b[i][j];
        }
    }
    
    cout<<endl<< "The Second matrix is: "<<endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << b[i][j] << "\t";
        }
        cout << endl;
    }

    // Perform matrix multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 3; k++) {
                sum += a[i][k] * b[k][j];
            }
            res[i][j] = sum;
            sum = 0;
        }
    }

    cout<< endl << "Resulting 3x3 matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}

