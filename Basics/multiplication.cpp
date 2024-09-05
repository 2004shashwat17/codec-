//multiplication table ?
#include <iostream>
using namespace std;
int main (){
  int n;
    cout<< "Enter the number"<< endl;
    cin >> n;
  for (int i=1 ; i<=n ;i++){
    cout << (n* i) << " ";
  }

  cout <<  endl;
  return 0;
}