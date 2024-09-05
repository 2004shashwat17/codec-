#include <iostream>
#include <cstring> // Include the cstring library for strlen function
using namespace std;

int main(){  
  // char arr[5] =  {'c','o','d','e','\0'};
  // cout << strlen(arr) << endl; // Correctly prints the length of the string
  // // "apna college" // string literals
  //1st cin Method :
  char word[30];
  cin >> word;
  cout<< word << endl;
  cout << strlen(word) << endl;
  //2nd getline method :
  char sentence[30];
  cin.getline(sentence,30,'*');
  cout << sentence << endl;
  return 0;
}
#include<iostream>
#include<cstring>
using namespace std;
int main(){
  char str1[100] = "mango";
  char str2[100] = "x";
   // cout << strcpy(str1, str2) << endl;
  cout << strcat(str1, str2) ;
  // cout << strcmp(str1, str2) << endl;
  return 0;
}
//c++ strings :
#include<iostream>
#include<string>
using namespace std;
int main(){
  string str = "hello";
  cout << str << endl;
  str = "yellow";
  cout << str << endl;
  string str2;
  // cin >> str2;
  getline(cin , str2 , '$');
  cout <<str2[1] << endl;
  // cout << str2 << endl;
  return 0;
}