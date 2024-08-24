// #include<iostream>
// using namespace std;

// //factorial
// int factorial(int n){
//   if(n == 0){
//     return 1;
//   }
//   return n * factorial(n-1);
// }
// int main(){
//   int ans = factorial(5);
//   cout << ans << endl;
//   return 0;
// }
//Number in Decreasing order ?
// #include<iostream>
// using namespace std;

// //factorial
// void print(int n){
//   if(n == 0){//base case
//     return ;
//   }
//   cout << n << " ";//work
//   print(n-1);//assume
// }
// int main(){
//   print(100);
//   return 0;
// }
//Stack Overflow :
// #include<iostream>
// using namespace std;
// void print(){
//   cout << "function called" << endl;
//   print();
// }
// int main(){
//   print();
//   return 0;
// }
//Sum of N natural Numbers ?
// #include<iostream>
// using namespace std;

// int sum(int n){
//     if(n == 1) { //base case
//       return 1;
//     }
//   return n + sum(n-1); //assume
// }

// int main(){
//   cout << sum(6) << endl; //work
//   return 0;
// }
//Print Nth Fibonacci Number ?
// #include<iostream>
// using namespace std;

// int fibonacci(int n) {
//   if(n == 0 || n == 1) {
//     return n;
//   }
//   return fibonacci(n-1) + fibonacci(n-2);
// }
// int main(){
//   cout << fibonacci(6) << endl;
//   return 0;
// }
//Check If array is sorted ?
// #include<iostream>
// using namespace std;
// bool isSorted(int arr[], int n, int i){
//   if(i == n-1){
//     return true; //base case
//   }
//   if(arr[i] > arr[i+1]){ 
//     return false;
//   }
//   return isSorted(arr, n, i+1);
// }
// int main() {
//   int arr1[5] = {1,2,3,4,5};  //sorted : 1
//   // int arr2[5] = {1,2,4,3,5};  //unsorted : 0

//   cout << isSorted(arr1, 5, 0);
//   // cout << isSorted(arr2, 5, 0);
  
//   return 0;
// }
//First Occurrence ?
// #include<iostream>
// #include<vector>
// using namespace std;

// int firstOccur(vector<int> arr, int i, int target){
//   if(i == arr.size()){ // base case
//     return -1;
//   }
//   if(arr[i] == target){ //inner loop
//     return i;
//   }
//   return firstOccur(arr, i+1, target); //assume
// }

// int main(){
//   vector<int> arr = {1,2,3,3,3,4};
//   cout << firstOccur(arr, 0, 3) << endl;
//   return 0;
// }
//Last Occurence ?
// #include<iostream>
// #include<vector>
// using namespace std;

// int lastOccur(vector<int> arr, int target ,int i){
//   if(i == arr.size()){ // base case
//     return -1;
//   }
//   int idxfound = lastOccur(arr, target, i+1);
//   if(idxfound == -1 && arr[i] == target){
//     return i;
//   }
//   return idxfound;
// }

// int main(){
//   vector<int> arr = {1,2,3,3,3,4};
//   cout << lastOccur(arr, 3, 0) << endl;
//   return 0;
// }
//Print X to the power N : o(n)
// #include<iostream>
// using namespace std;
// int power(int x){
//   if(x == 0){
//     return 1;
//   }
//   return x * x;
// }
//0(log n)
// int power(int x, int n){
//   if(n == 0){
//     return 1;
//   }
  
//   int halfPow = power(x, n/2);
//   int halfPowSquare = halfPow * halfPow;

//   if(n % 2 != 0){
//     //odd
//     return x * halfPowSquare;
//   }
//   return halfPowSquare;
// }
// int main(){
//   int ans = power(2 , 10);
//   cout << ans << endl;
//   return 0;
// }




