//Bubble Sort
#include<iostream>
using namespace std;

void print (int *arr, int n){
  for(int i=0; i<n ; i++){
    cout <<arr[i]<< endl;
  }
  cout << endl;
}
void bubblesort(int *arr,int n){
  for(int i=0; i<n-1 ;i++){
    bool isSwap = false;//optimized
    for(int j=0; j<n-i-1; j++){
      if(arr[j]>arr[j+1]){
        swap(arr[j],arr[j+1]);
      }
    }
    if(!isSwap){
      return;
    }
  }
  print(arr, n);
}
int main(){
  // int arr[5]={2,4,5,3,1};
  int arr[10] = {1,2,3,4,5,6,7,8,9,10};
  bubblesort(arr, 5);
  cout << endl;
  return 0;
}