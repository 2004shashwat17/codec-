/* pattern 1 :
1 1 1 1
2 2 2 2
3 3 3 3
4 4 4 4 */
#include <iostream>
using namespace std;

int main () {
  //outer loop
  for (int i=1 ; i<=4 ; i++){
    //inner loop
    for (int j=1 ; j<=4 ; j++){
      //work
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}