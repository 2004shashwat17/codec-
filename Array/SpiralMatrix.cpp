//Spiral Matrix ?
#include<iostream>
using namespace std;

void spiralmatrix(int mat[][4], int n, int m) {
    int srow = 0, scol = 0, erow = n - 1, ecol = m - 1;

    while (srow <= erow && scol <= ecol) {
        // Top
        for (int j = scol; j <= ecol; j++) {
            cout << mat[srow][j] << " ";
        }
        srow++;

        // Right
        for (int i = srow; i <= erow; i++) {
            cout << mat[i][ecol] << " ";
        }
        ecol--;

        // Bottom
        if (srow <= erow) {
            for (int j = ecol; j >= scol; j--) {
              if(srow == erow){//middle
                break;
              }
                cout << mat[erow][j] << " ";
            }
            erow--;
        }

        // Left
        if (scol <= ecol) {
            for (int i = erow; i >= srow; i--) {
              if(scol == ecol){//middle
                break;
              }
                cout << mat[i][scol] << " ";
            }
            scol++;
        }
    }
    cout << endl;
}

int main() {
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
  int matrix2[3][4] = {
         {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12}, 
  };
    spiralmatrix(matrix, 4, 4);
  spiralmatrix(matrix2, 3, 4);
    return 0;
}