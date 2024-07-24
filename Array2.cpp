//printing subarrays ?
// #include<iostream>
// using namespace std;

// void printsubarrays(int *arr, int n){
//   for(int start=0; start<n; start++){
//       for(int end=start; end<n; end++){
//         for(int i=start; i<=end; i++){
//           cout << arr[i];
//         }
//         cout<< ", ";
//       }
//     cout << endl;
//   }
// }

// int main(){
//   int arr[5] = {1,2,3,4,5};
//   int n = 5;

//   printsubarrays(arr, n);
//   return 0;
// }
//Max Subarray sum(Brute force approach) ?
// #include<iostream>
// #include <climits>
// using namespace std;
// int maxSubarraySum1(int *arr, int n){ 
//   int maxSum = INT_MIN;
  
//   for(int start=0; start<n; start++){
//     for(int end=start; end<n; end++){
//       int currsum = 0;
//       for(int i=start; i<=end; i++){
//         currsum += arr[i];
//       }
//       cout << currsum << ",";
//       maxSum = max(maxSum, currsum);
//     }
//     cout << endl;
//   }
//   cout << "maximum subarray sum = "<< maxSum << endl;
//   return 0;
// }

// int main(){
//   int arr[6] = {2,-3,6,-5,4,2};
//   int n = sizeof(arr)/sizeof(int);
//   maxSubarraySum1(arr, n);
//   return 0;
// }
//Optimized version of max subarray sum ?
// #include<iostream>
// #include<climits>
// using namespace std;
// void maxSubarraySum2(int *arr, int n){
//   int maxSum = INT_MIN;
//   for(int start=0; start<n; start++){
//     int currsum = 0;
//     for(int end=start; end<n; end++){
//       currsum += arr[end];
//       maxSum = max(maxSum , currsum);
//     }
//   }
//   cout <<" maximum subarray sum =" <<maxSum << endl;
// }
// int main(){
//   int arr[6]= {2,-3,6,-5,4,2};
//   int n = sizeof(arr)/sizeof(int);
//   maxSubarraySum2(arr, n);
//   return 0;
// }
//KADANE'S ALGORITHM ?
// #include<iostream>
// #include<climits>
// using namespace std;
// void maxsubarray3 (int *arr, int n){
//   int maxSum = INT_MIN;
//   int currSum = 0;

//   for(int i=0; i<n; i++){
//     currSum += arr[i];
//     maxSum = max(currSum , maxSum);
//     if(currSum < 0){
//       currSum = 0;
//     }
//   }
//   cout <<" maximum subarray sum = " <<maxSum << endl;
// }

// int main(){
//   int arr[6] = {2,-3,6,-5,4,2};
//   int n = sizeof(arr)/sizeof(int);
//   maxsubarray3(arr, n);
//   return 0;
// }
//Buy & sell stocks ?
// #include<iostream>
// #include<climits>
// using namespace std;
// void maxProfit(int *prices, int n){
//   int bestbuy[10];
//   bestbuy[0] = INT_MAX;
//   for(int i=1; i<n; i++){
//     bestbuy[i] = min(bestbuy[i-1], prices[i-1]);
//   }

//   int maxProfit = 0;
//   for(int i=0 ; i<n ; i++){
//     int currProfit = prices[i] - bestbuy[i];
//     maxProfit = max(maxProfit , currProfit);
//   }
//   cout << "max Profit = "<< maxProfit << endl;
// }
// int main(){
//   int prices[6]= {7,1,5,3,6,4};
//   int n = sizeof(prices)/sizeof(int);

//   maxProfit(prices, n);
//   return 0;
// }
//Trapping Water ?
// #include<iostream>
// using namespace std;

// void trap(int *height , int n){
//   int leftMax[20], rightMax[20];
//   leftMax[0]= height[0];
//   rightMax[n-1] = height[n-1];

//   for(int i=1;i<n;i++){
//     leftMax[i] = max(leftMax[i-1], height[i-1]);
//   }
//   for(int i=n-2;i>=0;i--){
//     rightMax[i] = max(rightMax[i+1], height[i+1]);
//   }

//   int waterTrapped = 0;
//   for(int i=0; i<n; i++){
//     int currWater = min(leftMax[i], rightMax[i]) - height[i];
//     if(currWater > 0){
//       waterTrapped += currWater;
//     }
//   }
//   cout <<"water Trapped = "<< waterTrapped << endl;
// }

// int main(){
//   int height[7] = {4,2,0,6,3,2,5};
//   int n = sizeof(height)/sizeof(int);
//   trap(height,n);
//   return 0;
// }