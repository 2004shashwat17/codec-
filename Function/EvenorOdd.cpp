//find the no even or odd ?
#include<iostream>
using namespace std;
int evenodd(int n){
  if(n% 2 == 0){
    return true;
  }else {
    return false;
  }
}
int main(){
  cout << evenodd(20)<< endl;
  return 0;
}