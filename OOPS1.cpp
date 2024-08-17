// #include<iostream>
// using namespace std;
// class Student {
// // By default class is private
// private: 
//   //Properties
//   string name;
// public:
//   float cgpa;

//   //Methods
//   void getPercentage(){
//     cout << (cgpa * 10) << endl;
//   }
// };
// int main(){
//   Student s1;
//   // s1.name = "shashwat";
//   s1.cgpa = 9.0;
//   cout << s1.cgpa << endl;
//   s1.getPercentage();
//   return 0;
// }
// Access Modifiers
// #include<iostream>
// #include<string>
// using namespace std;

// class Student{
// private:
//   string name;
//   float cgpa;

// public:
//   void getPercentage(){
//     cout << (cgpa * 10) << endl;
//   }
//   //Setters
//   void setName(string s){
//     name = s;
//   }
//   void setCgpa(float cg){
//     cgpa = cg;
//   } 
//   //Getters
//   string getName(){
//     return name;
//   }
//   float getCgpa(){
//     return cgpa;
//   } 
// };
// int main(){
//   Student s1;
//   s1.setName("Shashwat");
//   s1.setCgpa(9.1);

//   cout << s1.getName() << endl;
//   cout << s1.getCgpa() << endl;
//   return 0;
// }
//Constructor ?
// #include<iostream>
// #include<string>
// using namespace std;
// class Car{
//   string name;
//   string color;

// public:
// Car(){
//   cout << "Constructor without params\n" ;
// } 
// Car(string name, string color) {
//     cout << "Constructor with parameters\n";
//     this->name = name;
//     this->color = color; 
//     // *this.color = color; same as the above line.
//   }
//   void start(){
//     cout << "car is started\n";
//   }
//   void stop(){
//     cout << "car is stopped\n";
//   }
//   //Getter
//   string getName(){
//     return name;
//   }
//   string getcolor(){
//    return name;
//   }
// };
// int main(){
//   Car c0;//Non-parameterized constructor
//   Car c1("maruti","white");//parameterized constructor
//   Car c2 ("fortuner","black");
//   cout <<"car name : "<< c1.getName() << endl;
//   cout <<"car color : "<<c1.getcolor() << endl;
//   return 0;
// }
//q1)Create a User class with properties : id(private), username(public) & password(private). It's id should be initialized in a parameterised constructor. It should have a Getter & Setter for Password .
// #include<iostream>
// using namespace std;
// class User{
// private:
//   int id;
//   string password;
// public:
//   string username;
//   User(int id){
//     this->id = id;
//   }
//   //Getter
//   string getPassword(){
//     return password;
//   }
//   //Setter
//   void setPassword(string password){
//     this->password = password;
//   }
// };
// int main(){
//   User u1(1);// Parametrized Constructor
//   u1.username= "shashwat";
//   u1.setPassword("abcd");
//   cout <<" username : "<< u1.username << endl;
//   cout <<" password : "<< u1.getPassword() << endl;
//   return 0;
// }
//Copy Constructor :
// #include<iostream>
// using namespace std;
// class Car{
// public:
//   string name;
//   string color;
//   Car(string name, string color){
//     this->name = name;
//     this->color = color;
//   }
// //Custom Copy Constructor
//   Car(Car &original){
//     cout << "Copying original to new..\n";
//     name = original.name;
//     color = original.color;
//   }
// };
// int main(){
//   Car c1("maruti","white");
//   Car c2(c1); // Default Copy Constructor //Custom Copy
//   cout << c2.name << endl; //Maruti800
//   cout << c1.color << endl; //White
//   return 0;
// }
//Shallow & Deep Copy :
// #include<iostream>
// using namespace std;
// class Car{
// public:
//   string name;
//   string color;
//   int *mileage;
//   Car(string name, string color){
//     this->name = name;
//     this->color = color;
//     mileage = new int;
//     *mileage = 12;
//   }
// //Custom Copy Constructor
//   Car(Car &original){
//     cout << "Copying original to new..\n";
//     name = original.name;
//     color = original.color;
//     mileage = new int;
//     *mileage = *original.mileage;
//   }
// };
// int main(){
//   Car c1("maruti","white");
//   Car c2(c1); // Default Copy Constructor //Custom Copy
//   cout << c2.name << endl; //Maruti800
//   cout << c1.color << endl; //White
//   cout << *c2.mileage << endl;
//   *c2.mileage = 10;
  
//   cout << *c1.mileage << endl; //10
//   return 0;
// }
//  Destructor :
// #include<iostream>
// using namespace std;
// class Car{
// public:
//   string name;
//   string color;
//   int *mileage;
//   Car(string name, string color){
//     this->name = name;
//     this->color = color;
//     mileage = new int;
//     *mileage = 12;
//   }
// //Custom Copy Constructor
//   Car(Car &original){
//     cout << "Copying original to new..\n";
//     name = original.name;
//     color = original.color;
//     mileage = new int;
//     *mileage = *original.mileage;
//   }
//   ~Car(){
//     cout << "deleting object..\n";
//     if(mileage != NULL) {
//       delete mileage;
//       mileage = NULL;
//     }
//   }
// };
// int main(){
//   Car c1("maruti","white");
//   cout << c1.name << endl; //Maruti800
//   cout << c1.color << endl; //White
//   cout << *c1.mileage << endl;
//   return 0;
// }
//Inheritance :
//Single Inheritance
// #include<iostream>
// using namespace std;
// class Animal {
// public:
//   string color;
//   void eat() {
//     cout << "eats\n";
//   }
//   void breathe() {
//     cout << "breaths\n";
//   }
// };
// class Fish : public Animal {
// public:
//   int fins;
//   void swim(){
//     cout << "swims\n";
//   }
// };
// int main(){
//   Fish f1;
//   f1.fins = 3;
//   cout << f1.fins << endl;
//   f1.swim();
//   f1.eat();
//   f1.breathe();
//   return 0;
// }
//Multi Level Inheritance :
// #include<iostream>
// using namespace std;

// class Animal{
// public:
//   void eat(){
//     cout << "eats\n";
//   }
//   void breathe(){
//    cout << "breathe\n";
//   }  
// };
// class Mamel : public Animal{
// public:
//   string bloodtype;

//   Mamel (){
//     bloodtype = "warm";
//   }
// };
// class Dog : public Mamel {
//   public:
//   void tailwig(){
//     cout << "a Dog wags its tail\n";
//   }
// };
// int main(){
//   Dog a1;
//   a1.eat();
//   a1.breathe();
//   a1.tailwig();
//   cout << a1.bloodtype << endl;
//   return 0;
// }
// MULTIPLE INHERITANCE :
// #include<iostream>
// using namespace std;

// class Teacher{
// public:
//   int salary;
//   string subject;
// };
// class student{
// public:
//   int rollno;
//   float cgpa;
// };
// class TA : public Teacher, public student{
// public:
//   string name;
// };
// int main(){
//   TA a1;
//   a1.name = "shashwat";
//   a1.salary = 1000;
//   a1.subject = "cs";
//   a1.cgpa = 7.8;
//   a1.rollno = 21;
//   cout << a1.name<< " "<< a1.salary <<" "<<a1.subject <<" "<<a1.cgpa <<" "<<a1.rollno<< endl;
//   return 0;
// }
//Heirarchial inheritance :
// #include<iostream>
// using namespace std;
// class Animal {
// public:
//   string color;
//   void eat() {
//     cout << "eats\n";
//   }
//   void breathe() {
//     cout << "breaths\n";
//   }
// };
// class Bird : public Animal {
// public:
//   void fly(){
//     cout << "fly\n";
//   }
// };
// class fish : public Animal {
// public:
//   void swim(){
//     cout << "swim\n";
//   }
// };
// class Mamath : public Animal {
// public:
//   void walk(){
//     cout << "walk\n";
//   }
// };
// int main(){
//   Mamath f1;
//   f1.eat();
//   f1.breathe();
//   f1.walk();
//   return 0;
// }