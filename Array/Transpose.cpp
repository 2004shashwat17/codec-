//q3)Write a program to Find Transpose of a Matrix ?
#include<iostream>
using namespace std;
void transposeofmatrix(int matrix[][3], int row, int columns){
 //Transpose the matrix
  int transpose[3][2] = {{0}};
  for(int i=0; i<row; i++){
    for(int j=0; j<columns; j++){
      transpose[j][i] = matrix[i][j];
    }
  }
  //Print the transpose matrix
  for(int i=0; i<columns; i++){
    for(int j=0; j<row; j++){
      cout << transpose[j][i] << " ";
    }
    cout << endl;
  }
}
int main(){
  int matrix[][3] = {{1,4,9},{11,4,3}};
  transposeofmatrix(matrix, 2, 3);
  return 0;
}