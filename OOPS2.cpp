//Function Overloading
// #include <iostream>
// #include <string>
// using namespace std;

// class Print {
//   public:
//     void show(int x){
//       cout <<"int : " << x << endl;
//     }
//     void show(string str){
//       cout <<"string : " << str << endl;
//     }
// };
// int main(){
//   Print p;
//   p.show(4);
//   p.show("shashwat");
//   return 0;
// }
//Operator Overloading
// #include <iostream>
// #include <string>
// using namespace std;

// class Complex {
//   int real;
//   int img;
// public:
//     Complex(int r,int i){
//       real = r;
//       img = i;
//     }

//     void showNum() {
//       cout << real << " + " << img << "i\n";
//     }

//     Complex operator + (Complex &c2) {
//       int resReal = this->real + c2.real;
//       int resImg = this->img + c2.real;
//       Complex c3(resReal, resImg);
//       return c3;
//     }
// };
// int main(){
//   Complex c1(1,2);
//   Complex c2(3,4);

//   c1.showNum();
//   c2.showNum();
//   Complex c3 = c1 + c2;
//   c3.showNum();
//   return 0;
// }
//Function Overriding 
// #include<iostream>
// using namespace std;
// class Parent {
// public:
//     void show() {
//       cout << "parent class show..\n";
//     }
// };
// class Child : public Parent {
// public:
//     void show() {
//       cout << "child class show..\n";
//     }
// };
// int main() {
//   Child child1;
//   child1.show();
//   return 0;
// }
//Virtual functions :
// #include<iostream>
// using namespace std;
// class Parent {
// public:
//     virtual void hello() {
//       cout << "parent class show..\n";
//     }
// };
// class Child : public Parent {
// public:
//     void hello() {
//       cout << "child class show..\n";
//     }
// };
// int main() {
//   Child child1;
//   Parent *ptr;
  
//   ptr = &child1;//Run Time Binding
//   ptr->hello();//Virtual Function
//   return 0;
// }
//Abstraction & Pure Virtual Function :
// #include<iostream>
// using namespace std;
// //Abstract class
// class Shape{
// public:
//   virtual void draw() = 0;//Abstract fnx, pure virtual fnx
// };
// class Circle : public Shape{
// public:
//       void draw() {
//         cout <<"draw circle\n";
//       }
// };
// class Square : public Shape{
// public:
//       void draw() {
//         cout <<"draw Square\n";
//       }
// };
// int main(){
//   Circle cir1;
//   cir1.draw();

//   Square squ1;
//   squ1.draw();

//   Shape s1;
//   s1.draw();
//   return 0;
// }
//Static Variables for functions :
// #include<iostream>
// #include<string>
// using namespace std;

// void counter() {
//   static int count = 0;
//   count++;
//   cout << "count: " << count << endl;
// }

// int main() {
//   counter();
//   counter();
//   counter();
//   return 0;
// }
//Static Variables for classes :
// #include<iostream>
// #include<string>
// using namespace std;

// class Example {
// public:
//   static int x;
// };
// int Example::x = 0;

// int main() {
//   Example eg1;
//   Example eg2;
//   Example eg3;
//   cout << eg1.x++ << endl; //0
//   cout << eg2.x++ << endl; //1
//   cout << eg3.x++ << endl; //2
//   return 0;
// }
//Static Objects :
// #include<iostream>
// #include<string>
// using namespace std;

// class Example {
// public:
//   Example() {
//     cout << "constructor\n";
//   }
//   ~Example() {
//     cout << "Destructor\n";
//   }
// };

// int main() {
//   int a = 0;
//   if(a == 0) {
//     static Example eg1;
//   }
//   cout << "code ending\n";
//   return 0;
// }
//Friends functions & class :
// #include<iostream>
// #include<string>
// using namespace std;

// class A {
//     string secret = "secret data";
//     friend class B;
//     friend void revealSecret(A &obj);
// };

// class B { //becomes a friend class of A
// public:
//     void showSecret(A &obj) {
//       cout << obj.secret << endl;
//     }
// };

// void revealSecret(A &obj){
//     cout << obj.secret << endl;
// }

// int main() {
//   A a1;
//   B b1;
//   //b1.showSecret(a1);
//   revealSecret(a1);
//   return 0;
// }
//q1) Create a class to store Complex numbers. Using operator overloading, create the logic to subtract one complex number from another.
// #include<iostream>
// using namespace std;
// class Complex{
//   int real;
//   int img;
// public :
//   Complex (int r, int i){
//     real = r;
//     img = i;
//   }
// void shownum(){
//   cout << real <<" - "<< img << "i\n";
// }
// //Overload the - operator
// Complex operator - (Complex &c2){
//   int resReal = this->real - c2.real;
//   int resImg = this->img - c2.img;
//   Complex c3(resReal, resImg);
//   return c3;
// }
// };

// int main(){
//   Complex c1(2,3);
//   Complex c2(4,5);
//   c1.shownum();
//   c2.shownum();
//   Complex c3 = c1 - c2;
//   c3.shownum();
//   return 0;
// }
//q2)Question 2 : Create a class BankAccount with private attributes accountNumber and balance. Implement public methods deposit(), withdraw(), and getBalance() to manage the account.
// #include<iostream>
// using namespace std;
// class Bankaccount {
// private :
//   int accountnumber;
//   double balance;
// public :
// Bankaccount ( int accnum , double bal){
//   accountnumber = accnum;
//   balance = bal;
// }
// void deposit(double amount){
//   balance += amount;
// }
// void withdraw(double amount){
//   if(amount <= balance){
//     balance -= amount;
//   } else {
//     cout << "Not sufficient balance for this withdrawal.\n";
//   }
// }
// double getBalance(){
//   return balance;
// }
// };
// int main(){
//   Bankaccount myAccount(12345, 500.0);
//   myAccount.deposit(150.0);
//   myAccount.withdraw(478.0);
//   cout << "Current Balance: Rs." << myAccount.getBalance() << endl;
//   return 0;
// }
//q3)Question 3 : Create a base class Person with attributes name and age. Derive a class Student from Person and add an additional attribute studentID. Implement a method displayStudentInfo( ) in the Student class to display all details.In main function Student class object will be created in this format: Student student("Alice", 20, "S12345");
// #include<iostream>
// using namespace std;
// class Person {
// protected:
// string name;
// int age;
// public:
//     Person(string n, int a) {
//       name = n;
//       age = a;
//     }
// };
// class Student : public Person {
// private :
//       string studentID;
// public :
//       Student(string n, int a, string id) : Person(n,a) {
//         studentID = id;
//       }
//     void displayStudentInfo() {
//       cout << "name : " << this->name << endl;
//       cout << "age : " << this->age << endl;
//       cout << "studentID : " << this->studentID << endl;
//     }
// };
// int main(){
//   Student student("Alice",20,"S12345");
//   student.displayStudentInfo();
//   return 0;
// }