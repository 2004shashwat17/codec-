//printing array using functions
#include<iostream>
using namespace std;

void printarr (int  nums [] , int n){
  for(int i=0; i<n ; i++){
    cout << nums[i] << ",";
  }
  cout << endl;
}
int main(){
  int arr[]= {1,2,3,4,5};
  int n = sizeof(arr)/sizeof(int);
  cout << "array size = " << sizeof(arr) << endl;
  printarr(arr,n);  
  return 0;
}