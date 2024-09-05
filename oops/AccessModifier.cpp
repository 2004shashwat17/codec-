// Access Modifiers
#include<iostream>
#include<string>
using namespace std;

class Student{
private:
  string name;
  float cgpa;

public:
  void getPercentage(){
    cout << (cgpa * 10) << endl;
  }
  //Setters
  void setName(string s){
    name = s;
  }
  void setCgpa(float cg){
    cgpa = cg;
  } 
  //Getters
  string getName(){
    return name;
  }
  float getCgpa(){
    return cgpa;
  } 
};
int main(){
  Student s1;
  s1.setName("Shashwat");
  s1.setCgpa(9.1);

  cout << s1.getName() << endl;
  cout << s1.getCgpa() << endl;
  return 0;
}