//q4) Valid Anagram ?
#include <iostream>
#include<string>
using namespace std;

bool isAnagram(string str1, string str2){
  if (str1.length() != str2.length()) {
    return false;
  }
  int count[26] = {0};
  for(int i=0; i<str1.length(); i++){
    count[str1[i] - 'a']++;
  }
  for(int i=0; i<str2.length(); i++){
    if(count[str2[i] - 'a'] == 0){
      cout << "not valid anagram" << endl;
      return false;
    }
    count[str2[i] - 'a']--;
  }
  cout << "Valid anagram\n";
  return true;
}
int main(){
  string str1 = "anagram";
  string str2 = "nagaram";
  isAnagram(str1, str2);
  return 0;
}