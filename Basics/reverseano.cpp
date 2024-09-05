//reverse a number :
#include<iostream>
using namespace std;

int main(){
  int n ;
  cout << "Enter the number :" ;
  cin >> n;
  int res = 0;
  while ( n > 0){
    int lastdigit =  n% 10;
    res = res * 10 + lastdigit;
    n/=10;
  }
  cout << "Reversed number : "<< res <<endl;
  return 0;
}