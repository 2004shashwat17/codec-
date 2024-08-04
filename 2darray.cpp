//Create & Access each elements in 2d array :
// #include<iostream>
// using namespace std;
// int main(){
//   int student[3][3] = { {100,100,100},
//                         {40,76,45},
//                         {65,76,89}};
//   cout << student[1][1] << endl;
//   return 0;
// }
//Input & Output in 2d array :
// #include<iostream>
// using namespace std;
// int main(){
//   int arr[3][4];
//   int n=3,m=4;
//   for(int i=0; i<n; i++) {
//     for(int j=0; j<m; j++){
//       cin >> arr[j][i];
//     }
//   }
//   for(int i=0; i<n; i++) {
//     for(int j=0; j<m; j++){
//       cout << arr[j][i] << " ";
//     }
//     cout << endl;
//   }
//   return 0;
// }
//Spiral Matrix ?
// #include<iostream>
// using namespace std;

// void spiralmatrix(int mat[][4], int n, int m) {
//     int srow = 0, scol = 0, erow = n - 1, ecol = m - 1;

//     while (srow <= erow && scol <= ecol) {
//         // Top
//         for (int j = scol; j <= ecol; j++) {
//             cout << mat[srow][j] << " ";
//         }
//         srow++;

//         // Right
//         for (int i = srow; i <= erow; i++) {
//             cout << mat[i][ecol] << " ";
//         }
//         ecol--;

//         // Bottom
//         if (srow <= erow) {
//             for (int j = ecol; j >= scol; j--) {
//               if(srow == erow){//middle
//                 break;
//               }
//                 cout << mat[erow][j] << " ";
//             }
//             erow--;
//         }

//         // Left
//         if (scol <= ecol) {
//             for (int i = erow; i >= srow; i--) {
//               if(scol == ecol){//middle
//                 break;
//               }
//                 cout << mat[i][scol] << " ";
//             }
//             scol++;
//         }
//     }
//     cout << endl;
// }

// int main() {
//     int matrix[4][4] = {
//         {1, 2, 3, 4},
//         {5, 6, 7, 8},
//         {9, 10, 11, 12},
//         {13, 14, 15, 16}
//     };
//   int matrix2[3][4] = {
//          {1, 2, 3, 4},
//       {5, 6, 7, 8},
//       {9, 10, 11, 12}, 
//   };
//     spiralmatrix(matrix, 4, 4);
//   spiralmatrix(matrix2, 3, 4);
//     return 0;
// }
//Diagonal Sum :
// #include<iostream>
// using namespace std;
// int diagonalSum(int mat[][4], int n){
//   int sum = 0;
//   //0(n)slightly optimized
//   for(int i=0; i<n; i++){
//     sum += mat[i][i]; //pd
//     if(i != n-i-1){
//       sum += mat[i] [n-i-1]; //sd
//     }
//   }
//   //0(n^2)
//   for(int i=0; i<n ; i++){ //rows
//     for(int j=0; j<n; j++){ //cols
//       if(i == j){
//         sum += mat[i][j];
//       }else if(j == n-i-1){
//         sum += mat[i][j];
//       }
//     }
//   }
//   cout << "sum = " << sum << endl;
//   return sum;
// }

// int main(){
//   int matrix[4][4] = {{1,2,3,4},
//   {5,6,7,8},{9,10,11,12},{13,14,15,16}};
//   // int matrix2[3][3] = {{1,2,3},
//   //                       {4,5,6},
//   //                       {7,8,9}};
//   diagonalSum(matrix, 4);
//   return 0;
// }
//Search in Sorted Array ?
//Staircase Approach :
// #include<iostream>
// using namespace std;

// bool search(int mat[][4] , int n, int m, int key){
//   int i=0, j = m-1;
// //0(n+m)
//   while(i<n && j>=0){
//     int cell = mat[i][j];
//     if( cell == key){
//       cout << "found at cell (" << i << "," << j << ")\n";
//       return true;
//     }else if(cell > key){
//       //left
//       j--;
//     }else{
//       //down
//       i++;
//     }
//   }
//   cout << "Key not found\n";
//   return false;
// }

// int main(){
//     int matrix[4][4] = {{1,2,3,4},
//     {5,6,7,8},{9,10,11,12},{13,14,15,16}};
//   search(matrix, 4,4,11);
//   return 0;
// }
//Matrix Pointers :
// #include<iostream>
// using namespace std;
// void funct(int mat[][4], int n, int m){
//   cout << "oth row value" << *(mat+1) << endl; //get value of pointer.
//   cout << "0th row ptr "<< mat +1 << endl; //get pointer
//   cout << *(*(mat + 2) + 2) << endl; //get full element
// }
// void funct2(int (*mat)[4], int n, int m){
  
// }
// int main(){
//   int mat[4][4] = {{1,2,3,4},
//       {5,6,7,8},{9,10,11,12},{13,14,15,16}};
//   funct(mat, 4, 4);
//   return 0;
// }
//ASSIGNMENT QUESTIONS :
//Q1) Print No of all 7's in 2d array ?
// #include<iostream>
// using namespace std;
// void totalnoof7(int arr[][3], int n, int m){
//   int count = 0;
//   for(int i=0 ; i<n ; i++){
//     for(int j=0; j<m ; j++){
//       if(arr[i][j] == 7){
//         count++;
//       }
//     }
//   }
//   cout <<"count of 7 is : "<< count << endl;
// }
// int main(){
//   int arr[2][3]={{4,7,8},{8,8,7}};
//   totalnoof7(arr,2,3);
//   return 0;
// }
//Q2) Print out the sum of the numbers in the second row of the “nums” array ?
// #include<iostream>
// using namespace std;
// void sumofsecondrow(int nums[][3], int n, int m){
//   int sum = 0;
//   for(int j=0 ; j<m ; j++){
//     sum +=nums[1][j];
//   }
//   cout << "sum is :" << sum << endl;
// }
// int main(){
//   int nums[3][3] = {{1,4,9},{11,4,3},{2,2,3}};
//   sumofsecondrow(nums, 3, 3);
//   return 0;
// }
//q3)Write a program to Find Transpose of a Matrix ?
// #include<iostream>
// using namespace std;
// void transposeofmatrix(int matrix[][3], int row, int columns){
//  //Transpose the matrix
//   int transpose[3][2] = {{0}};
//   for(int i=0; i<row; i++){
//     for(int j=0; j<columns; j++){
//       transpose[j][i] = matrix[i][j];
//     }
//   }
//   //Print the transpose matrix
//   for(int i=0; i<columns; i++){
//     for(int j=0; j<row; j++){
//       cout << transpose[j][i] << " ";
//     }
//     cout << endl;
//   }
// }
// int main(){
//   int matrix[][3] = {{1,4,9},{11,4,3}};
//   transposeofmatrix(matrix, 2, 3);
//   return 0;
// }
