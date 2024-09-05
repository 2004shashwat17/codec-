//For a positive N ,WAP that print sall the primenumbers from 2toN.(AssumeN>=2) ?
#include<iostream>
using namespace std;
int main(){
  int n;
  cout << "Enter the number :";
  cin >> n;
  for(int i=2; i<=n; i++){
    int curr = i;
    bool isprime = true;
    for (int j=2 ; j*j<=i; j++){
      if(curr % j == 0){
        isprime = false;
      }
    }
    if(isprime){
      cout << curr << " ";
    }
  }
  cout << endl;
  return 0;
}