//Matrix Pointers :
#include<iostream>
using namespace std;
void funct(int mat[][4], int n, int m){
  cout << "oth row value" << *(mat+1) << endl; //get value of pointer.
  cout << "0th row ptr "<< mat +1 << endl; //get pointer
  cout << *(*(mat + 2) + 2) << endl; //get full element
}
void funct2(int (*mat)[4], int n, int m){
  
}
int main(){
  int mat[4][4] = {{1,2,3,4},
      {5,6,7,8},{9,10,11,12},{13,14,15,16}};
  funct(mat, 4, 4);
  return 0;
}