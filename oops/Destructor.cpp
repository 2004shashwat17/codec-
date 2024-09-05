//  Destructor :
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
  ~Car(){
    cout << "deleting object..\n";
    if(mileage != NULL) {
      delete mileage;
      mileage = NULL;
    }
  }
};
int main(){
  Car c1("maruti","white");
  cout << c1.name << endl; //Maruti800
  cout << c1.color << endl; //White
  cout << *c1.mileage << endl;
  return 0;
}