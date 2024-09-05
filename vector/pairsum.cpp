// Q1 PAIR SUM ?
//Pointer Approach : 0(n)
#include <iostream>
#include <vector>
using namespace std;

vector<int> pairsum(vector<int> arr, int target){
  int st = 0, end = arr.size()-1;
  int currSum = 0;
  vector<int> ans;

  while(st < end){
    currSum = arr[st] + arr[end];
    if(currSum == target){
      ans.push_back(st);
      ans.push_back(end);
      return ans;
    }else if (currSum > target){
      end --;
    } else {
      st ++;
    }
  }
  return ans;
}

int main(){
  vector<int> vec = {2,7,11,15};
  int target = 9;
  vector<int> ans = pairsum(vec, target);
  cout << ans[0] << "," << ans[1] << endl;
  return 0;
}
// Brute Force Approach: 0(n^2)
#include <iostream>
#include <vector>
using namespace std;

vector<int> pairsum(vector<int> arr, int target){
  vector<int> ans;

for(int i=0 ; i<arr.size(); i++){
  for(int j=i+1; j<arr.size(); j++){
    if(arr[i] + arr[j] == target){
      ans.push_back(i);
      ans.push_back(j);
      return ans;
    }
  }
}  
return ans;
}
int main(){
  vector<int> vec = {2,7,11,15};
  int target = 9;
  vector<int> ans = pairsum(vec, target);
  if(!ans.empty()){
    cout << ans[0] << "," << ans[1] << endl;
  }else{
    cout << "No valid pair found." << endl;
  }
  return 0;
}