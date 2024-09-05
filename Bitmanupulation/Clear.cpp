//q1 Write a Function to clear the range of bits from i to j in a given number. (i & j are counted backwards from the right end of the number)
#include<iostream>
using namespace std;

int cleartherange(int num, int i, int j){
  int a = (~0) << (j+1);
  int b = (1 << i) - 1;
  int mask = a | b;
  num = num & mask;
  return num;
}
int main(){
  cout << cleartherange(15, 1, 3) << endl; 
  return 0;
}