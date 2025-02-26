//FirstOccurrence ?
#include<iostream>
#include<vector>
using namespace std;

int firstOccur(vector<int> arr, int i, int target){
  if(i == arr.size()){ // base case
    return -1;
  }
  if(arr[i] == target){ //inner loop
    return i;
  }
  return firstOccur(arr, i+1, target); //assume
}

int main(){
  vector<int> arr = {1,2,3,3,3,4};
  cout << firstOccur(arr, 0, 3) << endl;
  return 0;
}