//for-each loop 
#include<iostream>
using namespace std;
int main(){
  string str ="shashwat saxena";
  // for(int i=0; i<str.length(); i++){
  //   cout << str[i] << endl;
  // }
  // cout << "\n";
  //2nd method:
  for(char ch: str ){
    cout << ch << endl;
  }
  cout << endl;
  return 0;
}