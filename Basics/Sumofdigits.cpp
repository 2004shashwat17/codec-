#include <iostream>
using namespace std;
int main() {
  int n ;
  cout << "Enter the number" << endl;
  cin >> n;
  int digsum = 0;
  
  while (n > 0){
    int lastdigit = n% 10;
    digsum+= lastdigit;
    n = n/ 10;
  }
  cout << "Sum  = " << digsum << endl;
  return 0;
}
//2nd option
#include <iostream>
using namespace std;
int main (){
  int n;
  cout << "Enter the number : " << endl;
  cin >> n;
  int digsum = 0;

  while( n > 0) {
    int lastdigit = n % 10;
    if (lastdigit % 2 != 0){
      digsum += lastdigit;
    }
    n/=10;
  }
  cout << "sum of digits:" << digsum << endl;
  return 0;
}