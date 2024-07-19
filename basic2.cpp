//digits of given number in reverse :
// #include<iostream>
// using namespace std;
// int main () {
//   int n;
//   cout << "Enter the number : ";
//   cin >> n;
//   int lastdigit;
//   while (n > 0){
//     lastdigit = n% 10;
//     cout << lastdigit << endl;
//     n/=10;
//   }
// }
//reverse a number :
// #include<iostream>
// using namespace std;

// int main(){
//   int n ;
//   cout << "Enter the number :" ;
//   cin >> n;
//   int res = 0;
//   while ( n > 0){
//     int lastdigit =  n% 10;
//     res = res * 10 + lastdigit;
//     n/=10;
//   }
//   cout << "Reversed number : "<< res <<endl;
//   return 0;
// }
// #include<iostream>
// using namespace std;

// int main(){
//   int i = 1;
//   while(i <= 10){
//     if(i==3){
//       break;
//     }
//     cout << i << endl;
//     i++;
//   }
//    cout <<"out of the loop" << endl;
//   return 0;
// }
// #include<iostream>
// using namespace  std;
// int main (){
//   int n;

//   do{
//     cout << "enter the number";
//     cin >> n;
//     if( n% 10 == 0){
//       continue;
//     }
//     cout << "you entered "<< n << endl;
//   }while(true);
  
//   return 0;
// }
//check for prime
// #include<iostream>
// using namespace std;
// int main (){
//   int n;
//   cout<< "Enter the number"<< endl;
//   cin >> n;
//   bool isprime = true;
  
//   for (int i=2 ; i<=n-1 ;i++){
//     if(n%i == 0){
//       isprime = false;
//       break;
//     }
//   }

//   if(isprime){
//     cout <<"number is prime"<<endl;
//   }else {
//     cout <<"number is NOT Prime"<< endl;
//   }
//   return 0;
// }
//check for prime (optimized) ?
// #include <iostream>
// #include <cmath>
// using namespace std;
// int main (){
//   int n;
//     cout<< "Enter the number"<< endl;
//     cin >> n;

//   bool isprime = true ;
//   for (int i=2 ; i <= sqrt(n) ; i++){
//     if( n % i == 0){
//       isprime = false;
//       break;
//     }
//   }
//   if(isprime){
//     cout << "number is Prime" << endl;
//   }else{
//     cout <<"number is NOT Prime"<< endl;
//   }
//   return 0;
// }
//to find the factorical fo the number ?
// #include <iostream>
// using namespace std;
// int main (){
//   int n;
//     cout<< "Enter the number"<< endl;
//     cin >> n;
//   int fact = 1;
//   for (int i=1 ; i<=n ;i++){
//     fact *=i;
//   }

//   cout << "factorial no ." << n << "=" << fact<< endl;
//   return 0;
// }
//multiplication table ?
// #include <iostream>
// using namespace std;
// int main (){
//   int n;
//     cout<< "Enter the number"<< endl;
//     cin >> n;
//   for (int i=1 ; i<=n ;i++){
//     cout << (n* i) << " ";
//   }

//   cout <<  endl;
//   return 0;
// }
//check the armstrong number ?
// #include <iostream>
// using namespace std;
// int main (){
//   int n;
//     cout<< "Enter the number"<< endl;
//     cin >> n;
//   int num = n;
//   int cubesum = 0;
//   while ( num > 0) {
//     int lastdigit = num % 10;
//     cubesum += lastdigit * lastdigit * lastdigit;
//     num/=10;
//   }

//   if( n == cubesum){
//     cout << "number is armstrong number"<< endl;
//   }else{
//     cout << "not armstrong"<<endl;
//   }
//   return 0;
// }
//For a positive N ,WAP that print sall the primenumbers from 2toN.(AssumeN>=2) ?
// #include<iostream>
// using namespace std;
// int main(){
//   int n;
//   cout << "Enter the number :";
//   cin >> n;
//   for(int i=2; i<=n; i++){
//     int curr = i;
//     bool isprime = true;
//     for (int j=2 ; j*j<=i; j++){
//       if(curr % j == 0){
//         isprime = false;
//       }
//     }
//     if(isprime){
//       cout << curr << " ";
//     }
//   }
//   cout << endl;
//   return 0;
// }
//fibonacci series ?
// #include<iostream>
// using namespace std;
// int main (){
//   int n;
//     cout << "Enter the number :";
//     cin >> n;
//   int first = 0 , sec = 1;
//   for (int i=2 ; i<=n ;i++){
//     int third = first + sec;
//     cout << third << " ";
//     first = sec;
//     sec = third;
//   }
//   cout << "\n";
//   return 0;
// }