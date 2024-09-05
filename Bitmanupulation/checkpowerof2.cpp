//Check for Power of 2 ?
#include<iostream>
using namespace std;
int powerof2 (int num){
  if(!(num & (num-1))){
    return true;
  } else{
    return false;
  }
}
int main(){
  cout << powerof2(4) << endl;
  return 0;
}