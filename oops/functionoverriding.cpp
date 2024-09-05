//Function Overriding 
#include<iostream>
using namespace std;
class Parent {
public:
    void show() {
      cout << "parent class show..\n";
    }
};
class Child : public Parent {
public:
    void show() {
      cout << "child class show..\n";
    }
};
int main() {
  Child child1;
  child1.show();
  return 0;
}