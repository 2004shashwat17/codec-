//q1) Create a class to store Complex numbers. Using operator overloading, create the logic to subtract one complex number from another.
#include<iostream>
using namespace std;
class Complex{
  int real;
  int img;
public :
  Complex (int r, int i){
    real = r;
    img = i;
  }
void shownum(){
  cout << real <<" - "<< img << "i\n";
}
//Overload the - operator
Complex operator - (Complex &c2){
  int resReal = this->real - c2.real;
  int resImg = this->img - c2.img;
  Complex c3(resReal, resImg);
  return c3;
}
};

int main(){
  Complex c1(2,3);
  Complex c2(4,5);
  c1.shownum();
  c2.shownum();
  Complex c3 = c1 - c2;
  c3.shownum();
  return 0;
}