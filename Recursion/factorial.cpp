//StackOverflow:
// #include<iostream>
// using namespace std;
// void print(){
//   cout << "function called" << endl;
//   print();
// }
// int main(){
//   print();
//   return 0;
// }

#include<iostream>
using namespace std;

//factorial
int factorial(int n){
  if(n == 0){
    return 1;
  }
  return n * factorial(n-1);
}
int main(){
  int ans = factorial(5);
  cout << ans << endl;
  return 0;
}