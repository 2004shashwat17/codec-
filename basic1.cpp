//print the largest of 3 numbers ?
// #include <iostream>
// using namespace std;
// int main (){
//   int a,b,c ;
//   cout << "Enter the 3 values :";
//   cin >> a >> b >> c ;
//   if (a >=b && a>=c){
//     cout << " The largest number is a"<< endl;
//   }else if (b >= c){
//     cout << "The largest number is b"<< endl;
//   }else{
//     cout << "the largest number is c"<< endl;
//   }
//   return 0;
// }
// Income tax calculator ?
// #include <iostream>
// using namespace std;
// int main () {
//   int income;
//   float tax ;
//   cout << "enter income (in lakhs): ";
//   cin >> income;
  
//   if(income < 5){
//     tax = 0;
//   }else if (income <= 10) {
//     tax = 0.2 * income;
//   }else{
//     tax = 0.3 * income;
//   }
//   cout <<"Tax = "<< (tax * 100000) << endl;
//   return 0;
// }
// #include<iostream>
// using namespace std;
// int main(){
//   int a,b;
//   char op;
  
//   cout << "enter a ";
//   cin >> a ;
//   cout << "enter b ";
//   cin >> b ;
//   cout << "enter the operator";
//   cin >> op;

//   switch(op) {
//     case '+' : cout << "a+b =" << (a+b) << endl;
//             break;
//     case '-' : cout << "a+b =" << (a-b) << endl;
//     break;
//     case '*' : cout << "a+b =" << (a*b) << endl;
//     break;
//     case '/' : cout << "a+b =" << (a/b) << endl;
//     break;
//     default : cout << "Invalid day"<<endl;
//   }
//   return 0;
// }
// #include<iostream>
// using namespace std;
// int main(){
//   int number;
//   cout << "enter the number";
//   cin >> number;
//   if (number > 0){
//     cout << "the number is positive";
//   }else if (number < 0) {
//     cout << " the number is negative";
//   }else{
//     cout << "its O";
//   }
//   return 0;
// }
// #include<iostream>
// using namespace std;
// int main() {
//   int year;
//   cout << "Enter the year";
//   cin >> year;
//   if ( year % 400 == 0){
//     cout << "Its is  a leap year";
//   }else if (year % 100 == 0) {
//     cout << "Its not a leap year";
//   }else if (year % 4 == 0){
//     cout << "Its a leap year";
//   }else {
//     cout << "Its not a leap year";
//   }
//   return 0;
// }
// #include<iostream>
// using namespace std;
// int main(){
//   int n;
//   cout << "Enter the number : ";
//   cin >> n;

//   int num = n;

//   int dig1 = num % 10;
//   num/=10;
//   int dig2 = num % 10;
//   num/=10;
//   int dig3 = num;

//   int cubsum = dig1*dig1*dig1 + dig2*dig2*dig2 + dig3*dig3*dig3;

//   if(cubsum == n){
//     cout << n << "Its an armstrong number :";
//   } else {
//     cout << n << "Its not an armstrong number :";
//   }
//   return 0;
// }
// #include <iostream>
// using namespace std;
// int main() {
//   int n;
//   cout << "Enter the number : " ;
//   cin >> n;
//    for(int i = 0 ; i <= n ; i++){
//      cout << i << " ";
//    }
//   return 0;
// }
// #include <iostream>
// using namespace std;
// int main(){
//   int n;
//   cout << "Enter the number :" ;
//   cin >> n;
//   int sum = 0;
//   for ( int i = 0 ; i<=n ; i++){
//     sum += i;
//     cout << sum  << " " ;
//   }
//   return 0;
// }
// #include <iostream>
// using namespace std;
// int main() {
//   int n ;
//   cout << "Enter the number" << endl;
//   cin >> n;
//   int digsum = 0;
  
//   while (n > 0){
//     int lastdigit = n% 10;
//     digsum+= lastdigit;
//     n = n/ 10;
//   }
//   cout << "Sum  = " << digsum << endl;
//   return 0;
// }
// #include <iostream>
// using namespace std;
// int main (){
//   int n;
//   cout << "Enter the number : " << endl;
//   cin >> n;
//   int digsum = 0;

//   while( n > 0) {
//     int lastdigit = n % 10;
//     if (lastdigit % 2 != 0){
//       digsum += lastdigit;
//     }
//     n/=10;
//   }
//   cout << "sum of digits:" << digsum << endl;
//   return 0;
// }
