// Sumof N natural Numbers ?
#include<iostream>
using namespace std;

int sum(int n){
    if(n == 1) { //base case
      return 1;
    }
  return n + sum(n-1); //assume
}

int main(){
  cout << sum(6) << endl; //work
  return 0;
}