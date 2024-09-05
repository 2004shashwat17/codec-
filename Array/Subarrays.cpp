//printing subarrays ?
#include<iostream>
using namespace std;

void printsubarrays(int *arr, int n){
  for(int start=0; start<n; start++){
      for(int end=start; end<n; end++){
        for(int i=start; i<=end; i++){
          cout << arr[i];
        }
        cout<< ", ";
      }
    cout << endl;
  }
}

int main(){
  int arr[5] = {1,2,3,4,5};
  int n = 5;

  printsubarrays(arr, n);
  return 0;
}
//Max Subarray sum(Brute force approach) ?
#include<iostream>
#include <climits>
using namespace std;
int maxSubarraySum1(int *arr, int n){ 
  int maxSum = INT_MIN;
  
  for(int start=0; start<n; start++){
    for(int end=start; end<n; end++){
      int currsum = 0;
      for(int i=start; i<=end; i++){
        currsum += arr[i];
      }
      cout << currsum << ",";
      maxSum = max(maxSum, currsum);
    }
    cout << endl;
  }
  cout << "maximum subarray sum = "<< maxSum << endl;
  return 0;
}

int main(){
  int arr[6] = {2,-3,6,-5,4,2};
  int n = sizeof(arr)/sizeof(int);
  maxSubarraySum1(arr, n);
  return 0;
}
//Optimized version of max subarray sum ?
#include<iostream>
#include<climits>
using namespace std;
void maxSubarraySum2(int *arr, int n){
  int maxSum = INT_MIN;
  for(int start=0; start<n; start++){
    int currsum = 0;
    for(int end=start; end<n; end++){
      currsum += arr[end];
      maxSum = max(maxSum , currsum);
    }
  }
  cout <<" maximum subarray sum =" <<maxSum << endl;
}
int main(){
  int arr[6]= {2,-3,6,-5,4,2};
  int n = sizeof(arr)/sizeof(int);
  maxSubarraySum2(arr, n);
  return 0;
}