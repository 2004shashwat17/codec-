//Static Variables for functions :
#include<iostream>
#include<string>
using namespace std;

void counter() {
  static int count = 0;
  count++;
  cout << "count: " << count << endl;
}

int main() {
  counter();
  counter();
  counter();
  return 0;
}
//Static Variables for classes :
#include<iostream>
#include<string>
using namespace std;

class Example {
public:
  static int x;
};
int Example::x = 0;

int main() {
  Example eg1;
  Example eg2;
  Example eg3;
  cout << eg1.x++ << endl; //0
  cout << eg2.x++ << endl; //1
  cout << eg3.x++ << endl; //2
  return 0;
}