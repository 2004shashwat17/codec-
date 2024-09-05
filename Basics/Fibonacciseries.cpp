//fibonacci series ?
#include<iostream>
using namespace std;
int main (){
  int n;
    cout << "Enter the number :";
    cin >> n;
  int first = 0 , sec = 1;
  for (int i=2 ; i<=n ;i++){
    int third = first + sec;
    cout << third << " ";
    first = sec;
    sec = third;
  }
  cout << "\n";
  return 0;
}