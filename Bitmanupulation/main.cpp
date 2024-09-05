#include<iostream>
using namespace std;
int main(){
  //Bitwise Operators
  cout << (3&5) << endl;
  cout << (3|5) << endl;
  cout << (3^5) << endl;
  cout << (~0) << endl; //-1
  cout << (7<<2) << endl;//Left Shift
  cout << (7>>2) << endl;//Right Shift
  cout << (8>>1) << endl;//Bitwise Operator
  return 0;
}
//get the ith bit :
#include<iostream>
using namespace std;
int getithBit(int num, int i){
  int bitMask = 1 << i;
  if(!(num & bitMask)){
    return 0;
  }else{
    return 1;
  }
}
int main(){
  cout << getithBit(6, 2) << endl;
  return 0;
}
//Set ith bit ?
#include<iostream>
using namespace std;
int setithbit(int num, int i) {
    int bitmask = 1 << i;
    return (num | bitmask);
}
int main() {
    cout << setithbit(6, 3) << endl;
    return 0;
}
//Clearithbit ?
#include<iostream>
using namespace std;
int setithbit(int num, int i) {
    int bitmask = ~ (1 << i);
    return (num & bitmask);
}
int main() {
    cout << setithbit(6, 1) << endl;
    return 0;
}
//Update the ith bit ?
#include<iostream>
using namespace std;
int update(int num,int i, int val){
  num = num & ~(1 << i); //clear bit
  num = num | (val << i); //set bit
  cout << num << endl;
}
int main(){
  cout << update(7,2,0) << endl;
  return 0;
}
//Clear Last ith bit ?
#include<iostream>
using namespace std;
void lastithbit(int num, int i){
  int bitmask = ~(1 << i);
  num = num & bitmask;
  cout << num << endl;
}
int main(){
 lastithbit(15, 2);
  return 0;
}
//Count Set Bits ?
#include<iostream>
using namespace std;
int countsetbits(int num){
  int count =0;
  while(num != 0){
    int lastdigit = num & 1;
    count += lastdigit;
    num = num >> 1;
  }
  cout << count << endl;
  return count;
}
int main(){
  countsetbits(10);
  return 0;
} 