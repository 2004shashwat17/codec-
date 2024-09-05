//Shallow & Deep Copy :
#include<iostream>
using namespace std;
class Car{
public:
  string name;
  string color;
  int *mileage;
  Car(string name, string color){
    this->name = name;
    this->color = color;
    mileage = new int;
    *mileage = 12;
  }
//Custom Copy Constructor
  Car(Car &original){
    cout << "Copying original to new..\n";
    name = original.name;
    color = original.color;
    mileage = new int;
    *mileage = *original.mileage;
  }
};
int main(){
  Car c1("maruti","white");
  Car c2(c1); // Default Copy Constructor //Custom Copy
  cout << c2.name << endl; //Maruti800
  cout << c1.color << endl; //White
  cout << *c2.mileage << endl;
  *c2.mileage = 10;
  
  cout << *c1.mileage << endl; //10
  return 0;
}