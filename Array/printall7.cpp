//Q1) Print No of all 7's in 2d array ?
#include<iostream>
using namespace std;
void totalnoof7(int arr[][3], int n, int m){
  int count = 0;
  for(int i=0 ; i<n ; i++){
    for(int j=0; j<m ; j++){
      if(arr[i][j] == 7){
        count++;
      }
    }
  }
  cout <<"count of 7 is : "<< count << endl;
}
int main(){
  int arr[2][3]={{4,7,8},{8,8,7}};
  totalnoof7(arr,2,3);
  return 0;
}