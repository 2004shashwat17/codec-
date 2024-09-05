//Leap year
#include<iostream>
using namespace std;
int main() {
  int year;
  cout << "Enter the year";
  cin >> year;
  if ( year % 400 == 0){
    cout << "Its is  a leap year";
  }else if (year % 100 == 0) {
    cout << "Its not a leap year";
  }else if (year % 4 == 0){
    cout << "Its a leap year";
  }else {
    cout << "Its not a leap year";
  }
  return 0;
}