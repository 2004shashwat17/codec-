//Search in Sorted Array ?
//Staircase Approach :
#include<iostream>
using namespace std;

bool search(int mat[][4] , int n, int m, int key){
  int i=0, j = m-1;
//0(n+m)
  while(i<n && j>=0){
    int cell = mat[i][j];
    if( cell == key){
      cout << "found at cell (" << i << "," << j << ")\n";
      return true;
    }else if(cell > key){
      //left
      j--;
    }else{
      //down
      i++;
    }
  }
  cout << "Key not found\n";
  return false;
}

int main(){
    int matrix[4][4] = {{1,2,3,4},
    {5,6,7,8},{9,10,11,12},{13,14,15,16}};
  search(matrix, 4,4,11);
  return 0;
}