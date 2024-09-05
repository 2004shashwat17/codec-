//Binary to Decimal Converter
#include<iostream>
using namespace std;

void bintodec(int binnum){
  int n = binnum;
  int decnum = 0;
  int pow = 1;

  while(n > 0){
    int last_digit = n%10;
    decnum += last_digit * pow;
    pow = pow*2;
    n = n/10;
  }
  cout << decnum << endl;
}
int main(){
  bintodec(1001);
  return 0;
}
//Decimal to Binary ?
#include<iostream>
using namespace std;
void dectobin(int decnum){
  int n = decnum;
  int pow = 1;
  int binNum = 0;

  while(n > 0){
    int rem = n % 2;
    binNum += rem * pow;
    n = n/2;
    pow = pow * 10;
  }
  cout << binNum << endl;
}
int main(){
  dectobin(4);
  return 0;
}