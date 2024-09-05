//output of array ?
#include <iostream>
using namespace std;
int main(){
  int arr[5] = {1, 2, 3, 4,5};
  int len = sizeof(arr) / sizeof(int); // to find the length of the array

  for(int idx = 0 ; idx <= len -1 ; idx ++ ){
    cout << arr[idx] << " ";
  }
//2nd option :
  for(int idx = 0 ; idx < len  ; idx ++ ){
    cout << arr[idx] << " ";
  }
  cout << endl;
  return 0;
}
//Input of array ?
#include<iostream>
using namespace std;
int main(){
  int n;
  cout << "Enter the array : ";
  cin >> n;
  
  int arr [n];
 // 2nd option // int n = sizeof(arr)/ sizeof(int);

  for (int i=0; i<n; i++){
    cin >> arr[i];
  }
  for (int i=0; i<n; i++){
    cout << arr[i] << ",";
  }
  cout << endl;
  return 0;
}