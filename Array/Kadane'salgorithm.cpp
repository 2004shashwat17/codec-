//KADANE'S ALGORITHM ?
#include<iostream>
#include<climits>
using namespace std;
void maxsubarray3 (int *arr, int n){
  int maxSum = INT_MIN;
  int currSum = 0;

  for(int i=0; i<n; i++){
    currSum += arr[i];
    maxSum = max(currSum , maxSum);
    if(currSum < 0){
      currSum = 0;
    }
  }
  cout <<" maximum subarray sum = " <<maxSum << endl;
}

int main(){
  int arr[6] = {2,-3,6,-5,4,2};
  int n = sizeof(arr)/sizeof(int);
  maxsubarray3(arr, n);
  return 0;
}