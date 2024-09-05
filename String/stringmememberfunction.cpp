//String Member Functions ?
#include<iostream>
#include<string>
using namespace std;
int main(){
  string str = "helloworld I Love Coding c++ and c++";
  cout << str.length() << endl;
  cout << str[2] << endl;
  cout << str.at(2) << endl;tr2
  cout << str.substr(5,5) << endl;
  cout << str.find("c++", 20) << endl;
  return 0;
}