//Copy Constructor :
#include<iostream>
using namespace std;
class Car{
public:
  string name;
  string color;
  Car(string name, string color){
    this->name = name;
    this->color = color;
  }
//Custom Copy Constructor
  Car(Car &original){
    cout << "Copying original to new..\n";
    name = original.name;
    color = original.color;
  }
};
int main(){
  Car c1("maruti","white");
  Car c2(c1); // Default Copy Constructor //Custom Copy
  cout << c2.name << endl; //Maruti800
  cout << c1.color << endl; //White
  return 0;
}