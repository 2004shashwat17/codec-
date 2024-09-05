//digits of given number in reverse :
#include<iostream>
using namespace std;
int main () {
  int n;
  cout << "Enter the number : ";
  cin >> n;
  int lastdigit;
  while (n > 0){
    lastdigit = n% 10;
    cout << lastdigit << endl;
    n/=10;
  }
}