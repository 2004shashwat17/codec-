//print the largest of 3 numbers ?
#include <iostream>
using namespace std;
int main (){
  int a,b,c ;
  cout << "Enter the 3 values :";
  cin >> a >> b >> c ;
  if (a >=b && a>=c){
    cout << " The largest number is a"<< endl;
  }else if (b >= c){
    cout << "The largest number is b"<< endl;
  }else{
    cout << "the largest number is c"<< endl;
  }
  return 0;
}