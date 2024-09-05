//Reverse an array with extra space ?
#include<iostream>
using namespace std;

void printarr(int *arr, int n){
  for(int i=0;i<n;i++){
    cout << arr[i] << ",";
  }
  cout << endl;
}

int main(){
  int arr[] = {5,4,3,9,2};
  int n = sizeof(arr)/ sizeof(int);

  int copyarr[n];
  for(int i=0; i<n ; i++){
    int j = n-i-1;
    copyarr[i] = arr[j];
  }
  for(int i=0; i<n ; i++){
     arr[i] = copyarr[i] ;
  }
  printarr(arr , n);
  return 0;
}
//Reverse an array without extra space ?
#include<iostream>
using namespace std;

void printarr(int *arr, int n){
  for(int i=0;i<n;i++){
    cout << arr[i] << ",";
  }
  cout << endl;
}
int main(){
  int arr[] = {5,4,3,9,2};
  int n = sizeof(arr)/ sizeof(int);

  int start = 0, end = n-1;

  while(start < end){
    // int temp = arr[start];
    // arr[start] = arr[end];
    // arr[end] = temp;
    //inbuid function
    swap(arr[start], arr[end]);
    start++;
    end--; 
  }
  
  printarr(arr , n);
  return 0;
}