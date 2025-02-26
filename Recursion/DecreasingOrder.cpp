#include<iostream>
using namespace std;

//factorial
void print(int n){
  if(n == 0){//base case
    return ;
  }
  cout << n << " ";//work
  print(n-1);//assume
}
int main(){
  print(100);
  return 0;
}