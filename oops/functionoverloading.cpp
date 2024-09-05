//Function Overloading
#include <iostream>
#include <string>
using namespace std;

class Print {
  public:
    void show(int x){
      cout <<"int : " << x << endl;
    }
    void show(string str){
      cout <<"string : " << str << endl;
    }
};
int main(){
  Print p;
  p.show(4);
  p.show("shashwat");
  return 0;
}