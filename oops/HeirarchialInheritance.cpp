//Heirarchial inheritance :
#include<iostream>
using namespace std;
class Animal {
public:
  string color;
  void eat() {
    cout << "eats\n";
  }
  void breathe() {
    cout << "breaths\n";
  }
};
class Bird : public Animal {
public:
  void fly(){
    cout << "fly\n";
  }
};
class fish : public Animal {
public:
  void swim(){
    cout << "swim\n";
  }
};
class Mamath : public Animal {
public:
  void walk(){
    cout << "walk\n";
  }
};
int main(){
  Mamath f1;
  f1.eat();
  f1.breathe();
  f1.walk();
  return 0;
}