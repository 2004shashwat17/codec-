
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