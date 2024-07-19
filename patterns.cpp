/* pattern 1 :
1 1 1 1
2 2 2 2
3 3 3 3
4 4 4 4 */
// #include <iostream>
// using namespace std;

// int main () {
//   //outer loop
//   for (int i=1 ; i<=4 ; i++){
//     //inner loop
//     for (int j=1 ; j<=4 ; j++){
//       //work
//       cout << i << " ";
//     }
//     cout << endl;
//   }
//   return 0;
// }
/* pattern 2 : star pattern : 
  * 
  * * 
  * * * 
  * * * *  */
// #include<iostream>
// using namespace std;
// int main(){
//   int n;
//   cout << "Enter the number : ";
//   cin >> n;
//   for (int i=1; i<=n ;i++){
//     for (int j=1; j<=i ; j++){
//       cout << "*";
//     }
//     cout << endl;
//   }
//   return 0;
// }
/* pattern 3 : Inverted star : 
* * * *
* * *
* * 
*    */
// #include<iostream>
// using namespace std;
// int main(){
//   int n;
//   cout << "Enter the number";
//   cin >> n;
//   for ( int i=1; i<=n ;i++){
//     for ( int j=1; j<=(n-i+1); j++){
//       cout << "*";
//     }
//     cout << endl;
//   }
//   return 0;
// }
/* pattern 4 :Character Pyramid : 
A
B C
D E F
G H I J*/
// #include <iostream>
// using namespace std;
// int main (){
//    int n;
//     cout << "Enter the number";
//     cin >> n;
//   char ch = 'A';
//   for (int i=1 ; i<=n; i++){
//     for (int j=1 ; j<=i ; j++){
//       cout << ch++;
//     }
//     cout << endl;
//   }
//   return 0;
// }
/* pattern 5 :Hollow Pattern :
****
*  *
*  *
****
*/
// #include<iostream>
// using namespace std;
// int main(){
//   int n;
//   cout << "Enter the number :" << endl;
//   cin >> n;
//   for (int i=1 ; i<=n ; i++){
//     cout << "*"; //first
//     for ( int j=1 ; j<=n-1 ; j++){
//       if ( i==1 || i==n){
//         cout << "*";
//       }else{
//         cout << " ";
//       }
//     }
//     cout << "*" << endl; //Last
//   }
//    return 0;
// }
/*Pattern 6 :Inverted and rotated half pyramid method :
        *
      * *
    * * *
  * * * *    
*/
// #include<iostream>
// using namespace std;
// int main (){
//   int n;
//   cout << "Enter the number :" << endl;
//   cin >> n;
//   for (int i=1 ; i<=n ; i++){
//     //spaces
//     for (int j=1 ; j<=n-i ; j++){
//       cout << " ";
//     }
//     //stars
//     for (int j=1 ; j<=i ; j++){
//       cout << "*";
//     }
//     cout << endl;
//   }
//   return 0;
// }
/* Pattern 7 : Floyd's Triangle Pattern :
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
*/
// #include<iostream>
// using namespace std;
// int main(){
//   int n;
//   cout << "Enter the number :"<< endl;
//   cin >> n;
//   int num = 1;
//   for (int i=1 ; i<=n ; i++){
//     for(int j=1; j<=i; j++){
//       cout << num++ << " ";
//     }
//     cout << endl;
//   }
//   return 0;
// }
/*Half Pyramid : Pattern 8
1
12
123
1234
*/
// #include<iostream>
// using namespace std;
// int main(){
//   int n = 5;
//   for(int i=1 ; i<=n ; i++){
//     for(int j=1; j<=i ; j++){
//       cout << j << " ";
//     }
//     cout << " " << endl;
//   }
//   return 0;
// }
/*Diamond Pattern : Pattern 9
        *
     *  *  *
  *  *  *  *  *
* *  *  *  *  *  * 
* *  *  *  *  *  *
  *  *  *  *  *
     *  *  *
        *       
*/
// #include<iostream>
// using namespace std;
// int main(){
//   int n = 4;
  
//   //1st half
//   for(int i=1 ; i<=n ; i++){
//     //spaces
//     for(int j=1 ; j<=n-i ; j++){
//       cout << " ";
//     }
//     //stars
//     for (int j=1 ; j<=2*i-1 ; j++){
//       cout << "*";
//     }
//     cout << endl;
//   }
//   //2nd half
//   for(int i=n ; i>=1 ; i--){
//     //spaces
//     for(int j=1 ; j<=n-i ; j++){
//       cout << " ";
//     }
//     //stars
//     for (int j=1 ; j<=2*i-1 ; j++){
//       cout << "*";
//     }
//     cout << endl;
//   }
//   return 0;
// }
/* Butterfly Pattern : Pattern 10
*      *
**    **
***  ***
********
********
***  ***
**    **
*      *
*/
// #include <iostream>
// using namespace std;
// int main(){
//   //upper half
//   int n = 4;
//   for ( int i=1 ; i<=n; i++){
//     //stars
//     for(int j=1 ; j<=i; j++){
//       cout << "*";
//     }
//     //spaces
//     for(int j=1 ; j<=2*(n-i); j++){
//       cout << " ";
//     }
//     //stars
//     for(int j=1 ; j<=i; j++){
//       cout << "*";
//     }
//     cout << " "<< endl;
//   }
//   //lower half
//   for ( int i=n ; i>=1; i--){
//     //stars
//     for(int j=1 ; j<=i; j++){
//       cout << "*";
//     }
//     //spaces
//     for(int j=1 ; j<=2*(n-i); j++){
//       cout << " ";
//     }
//     //stars
//     for(int j=1 ; j<=i; j++){
//       cout << "*";
//     }
//     cout << " "<< endl;
//   }
//   return 0;
// }
/* pattern 11 : Triangle Pattern
1
01
010
1010
*/
// #include<iostream>
// using namespace std;
// int main(){
//   int n = 4;
//   bool val = true;
//   for (int i=1; i<=n ; i++){
//     for(int j=1; j<=i; j++) {
//       cout << val << " ";
//       val = !val;
//     }
//     cout << "\n";
//   }
//   return 0;
// }
/*Rhombus Pattern: Pattern 12
    *****
   *****
  *****
 *****
*****
*/
// #include<iostream>
// using namespace std;
// int main (){
//   int n= 5;
//   for (int i=0; i<=n ; i++){ 
//     //spaces
//     for(int j=0 ; j<=n-i-1 ;j++){
//       cout << " ";
//     }
//     //stars
//     for(int j=0 ; j<n ; j++){
//       cout << "*";
//     }
//     cout << endl;
//   }
//   return 0;
// }
/*Pattern 13 : Palindrome Pattern
*/
// #include<iostream>
// using namespace std;
// int main (){
//   int n = 5;
//   for(int i=1 ; i<=n ; i++){
//     //spaces
//     for(int j=1 ; j<=n-i ; j++){
//       cout << " ";
//       // nums backward
//       for(int j=i; j>=1 ; j--){
//         cout << j;
//       }
//       //nums forward
//       for(int j=2; j<=i ; j++){
//         cout << j;
//       }
//       cout << " " << endl;
//     }
    
//   }
//   return 0;
// }