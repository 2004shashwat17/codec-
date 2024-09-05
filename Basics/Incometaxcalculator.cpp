// Income tax calculator ?
#include <iostream>
using namespace std;
int main () {
  int income;
  float tax ;
  cout << "enter income (in lakhs): ";
  cin >> income;
  
  if(income < 5){
    tax = 0;
  }else if (income <= 10) {
    tax = 0.2 * income;
  }else{
    tax = 0.3 * income;
  }
  cout <<"Tax = "<< (tax * 100000) << endl;
  return 0;
}
// Using Switch
#include<iostream>
using namespace std;
int main(){
  int a,b;
  char op;
  
  cout << "enter a ";
  cin >> a ;
  cout << "enter b ";
  cin >> b ;
  cout << "enter the operator";
  cin >> op;

  switch(op) {
    case '+' : cout << "a+b =" << (a+b) << endl;
            break;
    case '-' : cout << "a+b =" << (a-b) << endl;
    break;
    case '*' : cout << "a+b =" << (a*b) << endl;
    break;
    case '/' : cout << "a+b =" << (a/b) << endl;
    break;
    default : cout << "Invalid day"<<endl;
  }
  return 0;
}