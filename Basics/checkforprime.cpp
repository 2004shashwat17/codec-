//check for prime
#include<iostream>
using namespace std;
int main (){
  int n;
  cout<< "Enter the number"<< endl;
  cin >> n;
  bool isprime = true;
  
  for (int i=2 ; i<=n-1 ;i++){
    if(n%i == 0){
      isprime = false;
      break;
    }
  }

  if(isprime){
    cout <<"number is prime"<<endl;
  }else {
    cout <<"number is NOT Prime"<< endl;
  }
  return 0;
}
//check for prime (optimized) ?
#include <iostream>
#include <cmath>
using namespace std;
int main (){
  int n;
    cout<< "Enter the number"<< endl;
    cin >> n;

  bool isprime = true ;
  for (int i=2 ; i <= sqrt(n) ; i++){
    if( n % i == 0){
      isprime = false;
      break;
    }
  }
  if(isprime){
    cout << "number is Prime" << endl;
  }else{
    cout <<"number is NOT Prime"<< endl;
  }
  return 0;
}