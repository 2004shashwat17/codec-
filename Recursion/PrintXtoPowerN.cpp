//PrintXto the power N : 
//o(n)
#include<iostream>
using namespace std;
int power(int x){
  if(x == 0){
    return 1;
  }
  return x * x;
}
//0(log n)
int power(int x, int n){
  if(n == 0){
    return 1;
  }
  
  int halfPow = power(x, n/2);
  int halfPowSquare = halfPow * halfPow;

  if(n % 2 != 0){
    //odd
    return x * halfPowSquare;
  }
  return halfPowSquare;
}
int main(){
  int ans = power(2 , 10);
  cout << ans << endl;
  return 0;
}
