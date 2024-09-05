// MULTIPLE INHERITANCE :
#include<iostream>
using namespace std;

class Teacher{
public:
  int salary;
  string subject;
};
class student{
public:
  int rollno;
  float cgpa;
};
class TA : public Teacher, public student{
public:
  string name;
};
int main(){
  TA a1;
  a1.name = "shashwat";
  a1.salary = 1000;
  a1.subject = "cs";
  a1.cgpa = 7.8;
  a1.rollno = 21;
  cout << a1.name<< " "<< a1.salary <<" "<<a1.subject <<" "<<a1.cgpa <<" "<<a1.rollno<< endl;
  return 0;
}