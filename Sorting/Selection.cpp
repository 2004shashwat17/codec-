//selection Sort ?
#include<iostream>
using namespace std;

void print(int arr[] , int n){
  for(int i=0 ; i<n;i++){
    cout<< arr[i] << " ";
  }
  cout << endl;
}

void selectionsort(int arr[], int n){
  for(int i=0; i<n-1; i++){
    int minidex = i;
    //loop for find minimum
    for(int j=i+1; j<n; j++){
      if(arr[j] < arr[minidex]){
        minidex = j;
      }
    }
    swap(arr[i] , arr[minidex]);
  }
  
  print(arr,n);
}
int main(){
  int arr[5] = {5,4,3,2,1};
  selectionsort(arr, 5);
  return 0;
}