#include<iostream>
using namespace std;

void funcInt() {
  int *ptr = new int;
  *ptr = 5;
  cout << *ptr;
  delete ptr;
}

void func(){
  int size;
  cin >> size;
  
  int *ptr = new int[size];
  
  int x = 1;
  for(int i=0; i<size; i++){
    ptr[i] = x;
    cout << ptr[i] << " ";
    x++;
  }
  cout << endl;

  delete [] ptr; //free
}
int* fun2(){
  int *ptr = new int;
  *ptr = 1200;
  cout << "ptr points to "<< *ptr << endl;
  return ptr;
}
int main(){  
  int *x = fun2();
  cout << *x << endl;
  funcInt();
  return 0;
}