#include<iostream>
using namespace std;
int main(){
  int number;
  cout << "enter the number";
  cin >> number;
  if (number > 0){
    cout << "the number is positive";
  }else if (number < 0) {
    cout << " the number is negative";
  }else{
    cout << "its O";
  }
  return 0;
}