//printthenumber it is prime or not ?
#include<iostream>
using namespace std;
bool isprime(int n){
  if(n == 1){
    return false;
  }
  for(int i=2 ;i <=n-1 ;i++){
    if(n% i == 0){
      return false;
    }
  }
  return true;
}
bool isprime2(int n){
  if(n == 1){
    return false;
  }
  for(int i=2 ;i*i<=n ;i++){
    if(n% i == 0){
      return false;
    }
  }
  return true;
}
int main(){
  cout << isprime2(4)<< endl;
  cout <<isprime(3)<<endl;
  return 0;
}