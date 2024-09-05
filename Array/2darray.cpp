//Create & Access each elements in 2d array :
#include<iostream>
using namespace std;
int main(){
  int student[3][3] = { {100,100,100},
                        {40,76,45},
                        {65,76,89}};
  cout << student[1][1] << endl;
  return 0;
}
//Input & Output in 2d array :
#include<iostream>
using namespace std;
int main(){
  int arr[3][4];
  int n=3,m=4;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++){
      cin >> arr[j][i];
    }
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++){
      cout << arr[j][i] << " ";
    }
    cout << endl;
  }
  return 0;
}