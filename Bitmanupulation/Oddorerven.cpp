//Check if odd and even using Bit Manupilation ?
#include<iostream>
using namespace std;
void oddoreven(int num){
  if(!(num & 1)){
    cout << "even\n";
  }
  else{
    cout << "odd\n";
  }
}
int main(){
  oddoreven(5);
  return 0;
}