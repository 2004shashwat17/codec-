// #include<iostream>
// using namespace std;

// void funcInt() {
//   int *ptr = new int;
//   *ptr = 5;
//   cout << *ptr;
//   delete ptr;
// }

// void func(){
//   int size;
//   cin >> size;
  
//   int *ptr = new int[size];
  
//   int x = 1;
//   for(int i=0; i<size; i++){
//     ptr[i] = x;
//     cout << ptr[i] << " ";
//     x++;
//   }
//   cout << endl;

//   delete [] ptr; //free
// }
// int* fun2(){
//   int *ptr = new int;
//   *ptr = 1200;
//   cout << "ptr points to "<< *ptr << endl;
//   return ptr;
// }
// int main(){  
//   int *x = fun2();
//   cout << *x << endl;
//   funcInt();
//   return 0;
// }
//2D DYNAMIC ARRAY:
// #include<iostream>
// using namespace std;

// int main() {
//     int rows, cols;
//     cout << "Enter the rows : ";
//     cin >> rows;  // Corrected from 'cout' to 'cin'
//     cout << "Enter the cols : ";
//     cin >> cols;
//     int **matrix = new int*[rows];
//     for(int i = 0; i < rows; i++) {
//         matrix[i] = new int[cols];
//     }
//     // Data store:
//     int x = 1;
//     for(int i = 0; i < rows; i++) {
//         for(int j = 0; j < cols; j++) {
//             matrix[i][j] = x++;
//             cout << matrix[i][j] << " ";// Print elements in the same row separated by spaces
//         }
//         cout << endl; 
//     }
//     cout << matrix[2][2] << endl;
//     cout << *(*(matrix+2) + 2 ) << endl;
//     // Clean up the dynamically allocated memory
//     for(int i = 0; i < rows; i++) {
//         delete[] matrix[i];
//     }
//     delete[] matrix;
//     return 0;
// }
//Vectors Introduction :
// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//   vector <int> vec1 = {1,2,3,4,5};
//   cout << vec1.size() << "\n";
//   vector <int> vec2(10,-1);
//   cout << vec2.size() << " "; 

//   for(int i=0; i<vec2.size(); i++){
//     cout << vec2[i] << endl;
//   }
//   cout << endl;
//   return 0;
// }
//Vector Implementation in Memory:
// #include<iostream>
// #include <vector>
// using namespace std;
// int main(){
//   vector<int> vec = {1,2,3,4};
//   cout << "size : "<< vec.size() << endl;
//   cout << "capacity : " << vec.capacity() << endl;

//   vec.push_back(5);
//   cout << "size : "<< vec.size() << endl;
//   cout << "capacity : " << vec.capacity() << endl;

//   vec.pop_back();
//   cout << "size : "<< vec.size() << endl;
//   cout << "capacity : " << vec.capacity() << endl;
//   return 0;
// }
// Q1 PAIR SUM ?
//Pointer Approach : 0(n)
// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> pairsum(vector<int> arr, int target){
//   int st = 0, end = arr.size()-1;
//   int currSum = 0;
//   vector<int> ans;

//   while(st < end){
//     currSum = arr[st] + arr[end];
//     if(currSum == target){
//       ans.push_back(st);
//       ans.push_back(end);
//       return ans;
//     }else if (currSum > target){
//       end --;
//     } else {
//       st ++;
//     }
//   }
//   return ans;
// }

// int main(){
//   vector<int> vec = {2,7,11,15};
//   int target = 9;
//   vector<int> ans = pairsum(vec, target);
//   cout << ans[0] << "," << ans[1] << endl;
//   return 0;
// }
// Brute Force Approach: 0(n^2)
// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> pairsum(vector<int> arr, int target){
//   vector<int> ans;

// for(int i=0 ; i<arr.size(); i++){
//   for(int j=i+1; j<arr.size(); j++){
//     if(arr[i] + arr[j] == target){
//       ans.push_back(i);
//       ans.push_back(j);
//       return ans;
//     }
//   }
// }  
// return ans;
// }
// int main(){
//   vector<int> vec = {2,7,11,15};
//   int target = 9;
//   vector<int> ans = pairsum(vec, target);
//   if(!ans.empty()){
//     cout << ans[0] << "," << ans[1] << endl;
//   }else{
//     cout << "No valid pair found." << endl;
//   }
//   return 0;
// }
