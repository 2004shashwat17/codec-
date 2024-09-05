//2D DYNAMIC ARRAY:
#include<iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter the rows : ";
    cin >> rows;  // Corrected from 'cout' to 'cin'
    cout << "Enter the cols : ";
    cin >> cols;
    int **matrix = new int*[rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    // Data store:
    int x = 1;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = x++;
            cout << matrix[i][j] << " ";// Print elements in the same row separated by spaces
        }
        cout << endl; 
    }
    cout << matrix[2][2] << endl;
    cout << *(*(matrix+2) + 2 ) << endl;
    // Clean up the dynamically allocated memory
    for(int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}