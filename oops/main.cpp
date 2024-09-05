#include<iostream>
using namespace std;
class Student {
// By default class is private
private: 
  //Properties
  string name;
public:
  float cgpa;

  //Methods
  void getPercentage(){
    cout << (cgpa * 10) << endl;
  }
};
int main(){
  Student s1;
  // s1.name = "shashwat";
  s1.cgpa = 9.0;
  cout << s1.cgpa << endl;
  s1.getPercentage();
  return 0;
}