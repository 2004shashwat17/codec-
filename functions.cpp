//product of 2 numbers?
// #include<iostream>
// using namespace std;
// int prod(int a, int b){
//    return a*b;
// }

// int main(){
//   cout << prod(20, 30) << endl;
// }
//find the no even or odd ?
// #include<iostream>
// using namespace std;
// int evenodd(int n){
//   if(n% 2 == 0){
//     return true;
//   }else {
//     return false;
//   }
// }
// int main(){
//   cout << evenodd(20)<< endl;
//   return 0;
// }
//factorial of an number ?
// #include<iostream>
// using namespace std;

// int fact(int n){
//   int fact = 1;
//   for (int i=1 ;i<=n ;i++){
//     fact*=i;
//   }
//   cout << fact <<endl;
//   return fact;
// }
// int main(){
//   fact(5);
//   return 0;
// }
//print the number it is prime or not ?
// #include<iostream>
// using namespace std;
// bool isprime(int n){
//   if(n == 1){
//     return false;
//   }
//   for(int i=2 ;i <=n-1 ;i++){
//     if(n% i == 0){
//       return false;
//     }
//   }
//   return true;
// }
// bool isprime2(int n){
//   if(n == 1){
//     return false;
//   }
//   for(int i=2 ;i*i<=n ;i++){
//     if(n% i == 0){
//       return false;
//     }
//   }
//   return true;
// }
// int main(){
//   cout << isprime2(4)<< endl;
//   cout <<isprime(3)<<endl;
//   return 0;
// }
//Binomial Coefficient ->
// #include<iostream>
// using namespace std;

// int factorial(int n){
//   int fact =1;
//   for(int i=1; i<=n ; i++){
//     fact*=i;
//   }

//   return fact;
// }
// int binCoeff (int n ,int r){
//   int val1 = factorial(n);
//   int val2 = factorial(r);
//   int val3 = factorial(n-r);

//   int result = val1 / (val2 * val3);
//   return result;
// }

// int main(){
//   cout << binCoeff(4,2) << endl;
//   return 0;
// }
//print the primes between 2 to n ?
// #include<iostream>
// using namespace std;

// bool isprime (int n){
//   if(n ==1){
//     return false;
//   }

//   for(int i=2; i*i<=n; i++){
//     if(n % i == 0){
//       return false;
//     }
//   }
//   return true;
// }

// void allprime (int n){
//   for(int i=2; i<=n; i++){
//     if(isprime(i)){
//       cout << i << " ";
//     }
//   }
//   cout << endl;
// }
// int main(){
//   allprime(13);
//   return 0;
// }
//calculate the sum of digits of a number?
// #include<iostream>
// using namespace std;

// int digsum (int n){
//   int res = 0;
//   while(n > 0 ){
//     res += n % 10;
//     n = n /10;
//   }
//   cout << res <<endl;
//   return res;
// }

// int main(){
//   digsum(23);
//   return 0;
// }
//
// #include<iostream>
// using namespace std;

// int sum (int a , int b){
//   return  a * a + b * b + 2 * a * b;
// }
// int main(){
//   int sum1 = sum(2,2);
//   cout << sum1 << endl;
//   return 0;
// }
//Write a function that prints the largest of 3 numbers?
// #include<iostream>
// using namespace std;

// int larg (int a , int b , int c){
//   if (a >= b & a>=c){
//     return a;
//   }else if(b >=c) {
//     return b;
//   }else{
//     return c;
//   }
// }

// int main(){
//   int largest = larg(3, 6, 7);
//   cout << largest << endl;
//   return 0;
// }
//function that accepts a character (ch) as parameters & returns the character that occurs after ch in the English alphabet ?

// #include<iostream>
// using namespace std;

// char alph(char ch){
//   if (ch == 'z'){
//     return 'a';
//   }else {
//     return  ch +1;
//   }
// }

// int main(){
//   char a = 'a';
//   a = alph(a);
//   cout << a << endl;
//   return 0;
// }
//function to check if a number is a palindrome ?
// #include<iostream>
// using namespace  std;

// int rev(int n){
//   int reverse = 0;
//   while(n > 0){
//     int lastdigit = n % 10;
//     reverse = reverse * 10 + lastdigit;
//     n =  n/10;
//   }
//   return reverse;
// }
// bool ispalindrome (int num){
//   int revnum = rev(num);
//   return num == revnum;
// }
// int main(){
//   int num = 121;
//   bool palindrome = ispalindrome(num);
//   cout << "The number " << num << " is " << (palindrome ? "" : "not ") << "a palindrome." << endl;
//   return 0;
// }