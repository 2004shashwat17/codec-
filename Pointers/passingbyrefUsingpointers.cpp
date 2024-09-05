//Passing By reference using pointers :
#include<iostream>
using namespace std;
void change(int *ptr){
  *ptr = 20;
  cout << *ptr << endl;
}
int main(){
  int a = 10;
  change(&a);

  cout << a << endl;
  return 0;
}