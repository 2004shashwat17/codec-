//Diagonal Sum :
#include<iostream>
using namespace std;
int diagonalSum(int mat[][4], int n){
  int sum = 0;
  //0(n)slightly optimized
  for(int i=0; i<n; i++){
    sum += mat[i][i]; //pd
    if(i != n-i-1){
      sum += mat[i] [n-i-1]; //sd
    }
  }
  //0(n^2)
  for(int i=0; i<n ; i++){ //rows
    for(int j=0; j<n; j++){ //cols
      if(i == j){
        sum += mat[i][j];
      }else if(j == n-i-1){
        sum += mat[i][j];
      }
    }
  }
  cout << "sum = " << sum << endl;
  return sum;
}

int main(){
  int matrix[4][4] = {{1,2,3,4},
  {5,6,7,8},{9,10,11,12},{13,14,15,16}};
  // int matrix2[3][3] = {{1,2,3},
  //                       {4,5,6},
  //                       {7,8,9}};
  diagonalSum(matrix, 4);
  return 0;
}