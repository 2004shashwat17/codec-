//function to check if a number is a palindrome ?
#include<iostream>
using namespace  std;

int rev(int n){
  int reverse = 0;
  while(n > 0){
    int lastdigit = n % 10;
    reverse = reverse * 10 + lastdigit;
    n =  n/10;
  }
  return reverse;
}
bool ispalindrome (int num){
  int revnum = rev(num);
  return num == revnum;
}
int main(){
  int num = 121;
  bool palindrome = ispalindrome(num);
  cout << "The number " << num << " is " << (palindrome ? "" : "not ") << "a palindrome." << endl;
  return 0;
}