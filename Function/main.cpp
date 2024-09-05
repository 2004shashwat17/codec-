//function that accepts a character (ch) as parameters & returns the character that occurs after ch in the English alphabet ?

#include<iostream>
using namespace std;

char alph(char ch){
  if (ch == 'z'){
    return 'a';
  }else {
    return  ch +1;
  }
}

int main(){
  char a = 'a';
  a = alph(a);
  cout << a << endl;
  return 0;
}
