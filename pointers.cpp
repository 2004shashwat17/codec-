// #include<iostream>
// using namespace std;
// int main(){
//   int *ptr = NULL;
//   cout << ptr << endl;

//   cout << *ptr << endl; // never derefrencie null pointer
//   // int a=10 ;
//   //first we declare the pointer *ptr then assigned address of that variable in that pointer
//   // int *ptr = &a;

//   // cout << ptr << endl; //print's the address
//   // cout << *ptr << endl; // prints the value of that variable
//   //change the value :
//   // *ptr = 20;
//   // cout << a << endl;
//   //pointer to pointer variable
//   // int **pptr = &ptr;
//   // cout << &ptr << " = " << pptr << endl;

//   // float pi = 3.14;
//   // float *ptr2 = &pi;

//   // cout << sizeof(ptr) << endl;
//   // cout << sizeof(ptr2) << endl;
//   //address of assigned variable a
//   // cout << &a << " = " << ptr << endl;
//   // cout << &pi << " = " << ptr2 << endl;
//   return 0;
// }
//Passing Arguments :
// #include <iostream>
// using namespace std;

// void change (int a) {
//   a = 20;
//   cout <<  a << endl;
// }
// int main() {
//   int a = 10;
//   change(a);

//   cout << a << endl;
//   return 0;
// } 
//Passing By reference using pointers :
// #include<iostream>
// using namespace std;
// void change(int *ptr){
//   *ptr = 20;
//   cout << *ptr << endl;
// }
// int main(){
//   int a = 10;
//   change(&a);

//   cout << a << endl;
//   return 0;
// }
// Reference Variable :
// #include<iostream>
// using namespace std;
// int main(){
//   int a = 10;
//   int &b = a; // &b is the refernce variable assignment
//   b=25; // change the variable value of b reflects to a also as it is location on same memory.
//   cout << a << endl;
//   cout << b << endl;
//   return 0;
// }
//Passing By reference using Reference variable :
// #include<iostream>
// using namespace std;
// void change(int &a){
//   a = 20;
//   cout << a << endl;
// }
// int main(){
//   int a = 10;
//   change(a);
//   cout << a << endl;
//   return 0;
// }