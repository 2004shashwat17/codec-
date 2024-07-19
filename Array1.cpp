//output of array ?
// #include <iostream>
// using namespace std;
// int main(){
//   int arr[5] = {1, 2, 3, 4,5};
//   int len = sizeof(arr) / sizeof(int); // to find the length of the array

//   for(int idx = 0 ; idx <= len -1 ; idx ++ ){
//     cout << arr[idx] << " ";
//   }
//2nd option :
//   for(int idx = 0 ; idx <len  ; idx ++ ){
//     cout << arr[idx] << " ";
//   }
//   cout << endl;
//   return 0;
// }
//Input of array ?
// #include<iostream>
// using namespace std;
// int main(){
//   int n;
//   cout << "Enter the array : ";
//   cin >> n;
  
//   int arr [n];
//  // 2nd option // int n = sizeof(arr)/ sizeof(int);

//   for (int i=0; i<n; i++){
//     cin >> arr[i];
//   }
//   for (int i=0; i<n; i++){
//     cout << arr[i] << ",";
//   }
//   cout << endl;
//   return 0;
// }
// Find largest & smallest element in array ?
// #include<iostream>
// using namespace std;
// int main() {
//   int arr[] = {5,4,3,9,12};
//   int n = sizeof(arr)/sizeof(int);

//   int max = arr[0];
//   int min = arr[0];
//   for(int i=0;i<n;i++){
//     if(arr[i] > max){
//       max = arr[i];
//     }
//     if(arr[i] < min){
//       min = arr[i];
//     }
//   }
//    cout << "minimum = "<< min << endl;
//   cout << "largest = "<< max << endl;
//   return 0;
// }
// #include<iostream>
// using namespace std;

// void func(int arr[]) {
//   arr[0] = 1000;
// }

// void func2(int *ptr) {
//   ptr[0] = 1000;
// }

// int main(){
//   int a =5;
//   int *ptr = &a;
//   cout << ptr << endl;

//   int arr[] = {1,2,3,4,5};
//   // int n = sizeof(arr)/sizeof(int);

//   func(arr);
//   func2(arr);
//   cout << arr[0] << endl;
//   cout << arr[0] << endl;
//   // cout << * arr << endl; // arr[0]
//   // cout << *(arr+1) << endl; //arr[1]
//   // cout << *(arr+2) << endl; // arr[2]
//   return 0;
// }
//printing array using functions
// #include<iostream>
// using namespace std;

// void printarr (int  nums [] , int n){
//   for(int i=0; i<n ; i++){
//     cout << nums[i] << ",";
//   }
//   cout << endl;
// }
// int main(){
//   int arr[]= {1,2,3,4,5};
//   int n = sizeof(arr)/sizeof(int);
//   cout << "array size = " << sizeof(arr) << endl;
//   printarr(arr,n);  
//   return 0;
// }
//Binary Search
// #include<iostream>
// using namespace std;

// int linear(int *arr, int n , int key){
//   for(int i=0; i<n; i++){
//     if(arr[i] == key){
//       return i;
//     }
//   }
//   return -1;
// }
// int main(){
//   int arr[] = {2,4,6,8,10,12,14,16};
//   int n = sizeof(arr)/sizeof(int);
//   cout << linear(arr, n, 10) << endl;;
//   return 0;
// }
//Reverse an array with extra space ?
// #include<iostream>
// using namespace std;

// void printarr(int *arr, int n){
//   for(int i=0;i<n;i++){
//     cout << arr[i] << ",";
//   }
//   cout << endl;
// }

// int main(){
//   int arr[] = {5,4,3,9,2};
//   int n = sizeof(arr)/ sizeof(int);

//   int copyarr[n];
//   for(int i=0; i<n ; i++){
//     int j = n-i-1;
//     copyarr[i] = arr[j];
//   }
//   for(int i=0; i<n ; i++){
//      arr[i] = copyarr[i] ;
//   }
//   printarr(arr , n);
//   return 0;
// }
//Reverse an array without extra space ?
// #include<iostream>
// using namespace std;

// void printarr(int *arr, int n){
//   for(int i=0;i<n;i++){
//     cout << arr[i] << ",";
//   }
//   cout << endl;
// }
// int main(){
//   int arr[] = {5,4,3,9,2};
//   int n = sizeof(arr)/ sizeof(int);

//   int start = 0, end = n-1;

//   while(start < end){
//     // int temp = arr[start];
//     // arr[start] = arr[end];
//     // arr[end] = temp;
//     //inbuid function
//     swap(arr[start], arr[end]);
//     start++;
//     end--; 
//   }
  
//   printarr(arr , n);
//   return 0;
// }
//Binary search ?
// #include<iostream>
// using namespace std;

// int binsearch(int *arr, int n, int key){
//   int st=0, end = n-1;

//   while(st <= end){
//     int mid = (st+end)/2;
//     if(arr[mid] == key){
//       return mid;
//     }
//     else if(arr[mid] < key){ //second half
//       st = mid + 1 ;
//     }
//     else{
//       end = mid -1; //1st half
//     }
//   }
//   return -1;
// }

// int main() {
//   int arr[] = { 2,4,6,8,10,12,14,16};
//   int n = sizeof(arr)/sizeof(int);
//   cout << binsearch(arr, n, 16) << endl;
//   return 0;
// }