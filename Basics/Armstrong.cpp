#include<iostream>
using namespace std;
int main(){
  int n;
  cout << "Enter the number : ";
  cin >> n;

  int num = n;

  int dig1 = num % 10;
  num/=10;
  int dig2 = num % 10;
  num/=10;
  int dig3 = num;

  int cubsum = dig1*dig1*dig1 + dig2*dig2*dig2 + dig3*dig3*dig3;

  if(cubsum == n){
    cout << n << "Its an armstrong number :";
  } else {
    cout << n << "Its not an armstrong number :";
  }
  return 0;
}
//check the armstrong number ?
#include <iostream>
using namespace std;
int main (){
  int n;
    cout<< "Enter the number"<< endl;
    cin >> n;
  int num = n;
  int cubesum = 0;
  while ( num > 0) {
    int lastdigit = num % 10;
    cubesum += lastdigit * lastdigit * lastdigit;
    num/=10;
  }

  if( n == cubesum){
    cout << "number is armstrong number"<< endl;
  }else{
    cout << "not armstrong"<<endl;
  }
  return 0;
}