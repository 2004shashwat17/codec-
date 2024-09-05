//Binary Search
#include<iostream>
using namespace std;

int linear(int *arr, int n , int key){
  for(int i=0; i<n; i++){
    if(arr[i] == key){
      return i;
    }
  }
  return -1;
}
int main(){
  int arr[] = {2,4,6,8,10,12,14,16};
  int n = sizeof(arr)/sizeof(int);
  cout << linear(arr, n, 10) << endl;;
  return 0;
}
//Binary search ?
#include<iostream>
using namespace std;

int binsearch(int *arr, int n, int key){
  int st=0, end = n-1;

  while(st <= end){
    int mid = (st+end)/2;
    if(arr[mid] == key){
      return mid;
    }
    else if(arr[mid] < key){ //second half
      st = mid + 1 ;
    }
    else{
      end = mid -1; //1st half
    }
  }
  return -1;
}

int main() {
  int arr[] = { 2,4,6,8,10,12,14,16};
  int n = sizeof(arr)/sizeof(int);
  cout << binsearch(arr, n, 16) << endl;
  return 0;
}