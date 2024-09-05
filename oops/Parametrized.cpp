//q1)Create a User class with properties : id(private), username(public) & password(private). It's id should be initialized in a parameterised constructor. It should have a Getter & Setter for Password .
#include<iostream>
using namespace std;
class User{
private:
  int id;
  string password;
public:
  string username;
  User(int id){
    this->id = id;
  }
  //Getter
  string getPassword(){
    return password;
  }
  //Setter
  void setPassword(string password){
    this->password = password;
  }
};
int main(){
  User u1(1);// Parametrized Constructor
  u1.username= "shashwat";
  u1.setPassword("abcd");
  cout <<" username : "<< u1.username << endl;
  cout <<" password : "<< u1.getPassword() << endl;
  return 0;
}