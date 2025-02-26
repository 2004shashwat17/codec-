//LastOccurence?
#include<iostream>
#include<vector>
using namespace std;

int lastOccur(vector<int> arr, int target ,int i){
  if(i == arr.size()){ // base case
    return -1;
  }
  int idxfound = lastOccur(arr, target, i+1);
  if(idxfound == -1 && arr[i] == target){
    return i;
  }
  return idxfound; 
}

int main(){
  vector<int> arr = {1,2,3,3,3,4};
  cout << lastOccur(arr, 3, 0) << endl;
  return 0;
}