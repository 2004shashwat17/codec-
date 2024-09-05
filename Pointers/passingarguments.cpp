//Passing Arguments :
#include <iostream>
using namespace std;

void change (int a) {
  a = 20;
  cout <<  a << endl;
}
int main() {
  int a = 10;
  change(a);

  cout << a << endl;
  return 0;
} 