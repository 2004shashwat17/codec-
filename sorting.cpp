//Bubble Sort
// #include<iostream>
// using namespace std;

// void print (int *arr, int n){
//   for(int i=0; i<n ; i++){
//     cout <<arr[i]<< endl;
//   }
//   cout << endl;
// }
// void bubblesort(int *arr,int n){
//   for(int i=0; i<n-1 ;i++){
//     bool isSwap = false;//optimized
//     for(int j=0; j<n-i-1; j++){
//       if(arr[j]>arr[j+1]){
//         swap(arr[j],arr[j+1]);
//       }
//     }
//     if(!isSwap){
//       return;
//     }
//   }
//   print(arr, n);
// }
// int main(){
//   // int arr[5]={2,4,5,3,1};
//   int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//   bubblesort(arr, 5);
//   cout << endl;
//   return 0;
// }
//selection Sort ?
// #include<iostream>
// using namespace std;

// void print(int arr[] , int n){
//   for(int i=0 ; i<n;i++){
//     cout<< arr[i] << " ";
//   }
//   cout << endl;
// }

// void selectionsort(int arr[], int n){
//   for(int i=0; i<n-1; i++){
//     int minidex = i;
//     //loop for find minimum
//     for(int j=i+1; j<n; j++){
//       if(arr[j] < arr[minidex]){
//         minidex = j;
//       }
//     }
//     swap(arr[i] , arr[minidex]);
//   }
  
//   print(arr,n);
// }
// int main(){
//   int arr[5] = {5,4,3,2,1};
//   selectionsort(arr, 5);
//   return 0;
// }
//Insertion Sort ?
// #include<iostream>
// using namespace std;
// void print(int arr[], int n){
//   for(int i=0; i<n ; i++ ){
//     cout << arr[i] << " ";
//   }
//   cout << endl;
// }
// void insertionsort (int *arr,int n ) { 
//   for(int i=1; i<n; i++){
//     int curr = arr[i];
//     int prev = i-1;
//     while(prev >= 0 && arr[prev] > curr){
//       swap(arr[prev], arr[prev+1]);
//       prev--;
//     }
//     arr[prev+1] = curr;
//   }
//   print(arr,n);
// }
// int main(){
//   int arr[5]= {5,4,3,2,1};
//   insertionsort(arr , 5);
//   return 0;
// }
//Counting Sort ?
// #include <iostream>
// #include <climits>
// using namespace std;

// void print(int arr[], int n) {
//     for (int i = 0; i < n; i++) { // Start loop from 0
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// void countingsort(int arr[], int n) {
//     int freq[10000] = {0}; // range
//     int minval = INT_MAX, maxval = INT_MIN;

//     // 1st step - O(n)
//     for (int i = 0; i < n; i++) {
//         freq[arr[i]]++;
//         minval = min(minval, arr[i]);
//         maxval = max(maxval, arr[i]);
//     }

//     // 2nd step - O(max - min)
//     for (int i = minval, j = 0; i <= maxval; i++) {
//         while (freq[i] > 0) {
//             arr[j++] = i;
//             freq[i]--;
//         }
//     }

//     print(arr, n);
// }

// int main() {
//     int arr[8] = {1, 4, 1, 3, 2, 4, 3, 7};
//     countingsort(arr, 8);
//     return 0;
// }
//In-Build sort function ?
// #include<iostream>
// #include<algorithm>
// using namespace std;

// void print(int arr[], int n) {
//     for (int i = 0; i < n; i++) { // Start loop from 0
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main(){
//     int arr[8] = {1,4,1,3,2,4,3,7};
//     sort(arr,arr+8); // Sort in Ascending Order
//     sort(arr,arr+8, greater<int>()); //Sort in Descending Order
//     print(arr,8);
//     return 0;
// }
// Sort the array in descending order using insertion sort -> char ch[]= {'f','b','a','e','c','d'} ?
// #include<iostream>
// using namespace std;

// void print(char arr[], int n) {
//     for(int i = 0; i < n; i++) {
//         cout << arr[i] << " , ";
//     }
//     cout << endl;
// }

// void insertionsort(char *arr, int n) { 
//     for(int i = 1; i < n; i++) {
//         char curr = arr[i];
//         int prev = i - 1;
//         while(prev >= 0 && arr[prev] < curr) {
//             arr[prev + 1] = arr[prev];
//             prev--;
//         }
//         arr[prev + 1] = curr;
//     }
//     print(arr, n);
// }

// int main() {
//     char ch[6] = {'f', 'b', 'a', 'e', 'c', 'd'};
//     insertionsort(ch, 6);
//     return 0;
// }
//use all sorting algorithm to sort an array in descending order for an array -> [3,6,2,1,8,7,4,5,3,1]?
// #include<iostream>
// #include<climits>
// using namespace std;

// void print(int arr[], int n) {
//     for(int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// void bubbleSort(int *arr, int n) {
//     for(int i = 0; i < n - 1; i++) {
//         bool isSwap = false; // optimized
//         for(int j = 0; j < n - i - 1; j++) {
//             if(arr[j] < arr[j + 1]) { // Changed > to <
//                 swap(arr[j], arr[j + 1]);
//                 isSwap = true;
//             }
//         }
//         if(!isSwap) {
//             return;
//         }
//     }
//     print(arr, n);
// }

// void selectionSort(int arr[], int n) {
//     for(int i = 0; i < n - 1; i++) {
//         int maxIndex = i; // Changed variable name
//         for(int j = i + 1; j < n; j++) {
//             if(arr[j] > arr[maxIndex]) { // Changed < to >
//                 maxIndex = j;
//             }
//         }
//         swap(arr[i], arr[maxIndex]);
//     }
//     print(arr, n);
// }

// void countingSort(int arr[], int n) {
//     int freq[10000] = {0}; // range
//     int minval = INT_MAX, maxval = INT_MIN;

//     for (int i = 0; i < n; i++) {
//         freq[arr[i]]++;
//         minval = min(minval, arr[i]);
//         maxval = max(maxval, arr[i]);
//     }

//     for (int i = maxval, j = 0; i >= minval; i--) { // Changed loop direction
//         while (freq[i] > 0) {
//             arr[j++] = i;
//             freq[i]--;
//         }
//     }
//     print(arr, n);
// }

// void insertionSort(int *arr, int n) {
//     for(int i = 1; i < n; i++) {
//         int curr = arr[i];
//         int prev = i - 1;
//         while(prev >= 0 && arr[prev] < curr) { // Changed > to <
//             arr[prev + 1] = arr[prev];
//             prev--;
//         }
//         arr[prev + 1] = curr;
//     }
//     print(arr, n);
// }

// int main() {
//     int arr[10] = {3,6,2,1,8,7,4,5,3,1};
//     insertionSort(arr, 10);
//     countingSort(arr, 10);
//     selectionSort(arr, 10);
//     bubbleSort(arr, 10);
//     return 0;
// }
