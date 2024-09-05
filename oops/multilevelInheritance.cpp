//Multi Level Inheritance :
#include<iostream>
using namespace std;

class Animal{
public:
  void eat(){
    cout << "eats\n";
  }
  void breathe(){
   cout << "breathe\n";
  }  
};
class Mamel : public Animal{
public:
  string bloodtype;

  Mamel (){
    bloodtype = "warm";
  }
};
class Dog : public Mamel {
  public:
  void tailwig(){
    cout << "a Dog wags its tail\n";
  }
};
int main(){
  Dog a1;
  a1.eat();
  a1.breathe();
  a1.tailwig();
  cout << a1.bloodtype << endl;
  return 0;
}