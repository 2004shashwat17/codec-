//Constructor ?
#include<iostream>
#include<string>
using namespace std;
class Car{
  string name;
  string color;

public:
Car(){
  cout << "Constructor without params\n" ;
} 
Car(string name, string color) {
    cout << "Constructor with parameters\n";
    this->name = name;
    this->color = color; 
    // *this.color = color; same as the above line.
  }
  void start(){
    cout << "car is started\n";
  }
  void stop(){
    cout << "car is stopped\n";
  }
  //Getter
  string getName(){
    return name;
  }
  string getcolor(){
   return name;
  }
};
int main(){
  Car c0;//Non-parameterized constructor
  Car c1("maruti","white");//parameterized constructor
  Car c2 ("fortuner","black");
  cout <<"car name : "<< c1.getName() << endl;
  cout <<"car color : "<<c1.getcolor() << endl;
  return 0;
}
