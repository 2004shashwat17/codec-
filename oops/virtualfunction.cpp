//Virtual functions :
#include<iostream>
using namespace std;
class Parent {
public:
    virtual void hello() {
      cout << "parent class show..\n";
    }
};
class Child : public Parent {
public:
    void hello() {
      cout << "child class show..\n";
    }
};
int main() {
  Child child1;
  Parent *ptr;
  
  ptr = &child1;//Run Time Binding
  ptr->hello();//Virtual Function
  return 0;
}