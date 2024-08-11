// #include <iostream>
// #include <cstring> // Include the cstring library for strlen function
// using namespace std;

// int main(){  
//   // char arr[5] =  {'c','o','d','e','\0'};
//   // cout << strlen(arr) << endl; // Correctly prints the length of the string
//   // // "apna college" // string literals
//   //1st cin Method :
//   char word[30];
//   cin >> word;
//   cout<< word << endl;
//   cout << strlen(word) << endl;
//   //2nd getline method :
//   char sentence[30];
//   cin.getline(sentence,30,'*');
//   cout << sentence << endl;
//   return 0;
// }
//q1) Convert to Uppercase & in lowercase ?
// #include<iostream>
// #include<cstring>
// using namespace std;
// void toUpper(char word[], int n){
//   for(int i=0; i<n; i++){
//     char ch = word[i];
//     if(ch>='A' && ch<='Z'){ // uppercase
//       continue;
//     }else{
//       word[i] = ch - 'a' + 'A'; // LowerCase
//     }
//   }
// }
// void toLower(char word[], int n){
//   for(int i=0; i<n; i++){
//     char ch = word[i];
//     if(ch>='a' && ch<='z'){ // uppercase
//       continue;
//     }else{
//       word[i] = ch - 'A' + 'a'; // LowerCase
//     }
//   }
// }
// int main(){
//   char word[] = "ApPle";
//   toUpper(word, strlen(word));
//   toLower(word, strlen(word));

//   cout << word << endl;
//   return 0;
// }
//q2)Reverse An Char Array ?
// #include<iostream>
// #include<cstring>
// using namespace std;

// void reverse(char word[], int n) {
//     int st = 0, end = n - 1;
//     while (st < end) {
//         swap(word[st], word[end]);
//         st++;
//         end--;
//     }
// }

// int main() {
//     char word[] = "code"; // Use double quotes for string literals
//     reverse(word, strlen(word));
//     cout << "reverse = " << word << endl;
//     return 0;
// }
//q3)Valid Palindrome ?
// #include<iostream>
// #include<cstring>
// using namespace std;

// bool isPalindrome(char word[], int n) {
//     int st = 0, end = n - 1;
//     while (st < end) {
//         if (word[st++] != word[end--]) {
//             cout << "Not a valid palindrome\n";
//             return false;
//         }
//     }
//     cout << "Valid palindrome\n";
//     return true;
// }

// int main() {
//     char word[] = "racecar";
//     isPalindrome(word, strlen(word));
//     return 0;
// }
// #include<iostream>
// #include<cstring>
// using namespace std;
// int main(){
//   char str1[100] = "mango";
//   char str2[100] = "x";
//    // cout << strcpy(str1, str2) << endl;
//   cout << strcat(str1, str2) ;
//   // cout << strcmp(str1, str2) << endl;
//   return 0;
// }
//c++ strings :
// #include<iostream>
// #include<string>
// using namespace std;
// int main(){
//   string str = "hello";
//   cout << str << endl;
//   str = "yellow";
//   cout << str << endl;
//   string str2;
//   // cin >> str2;
//   getline(cin , str2 , '$');
//   cout <<str2[1] << endl;
//   // cout << str2 << endl;
//   return 0;
// }
//for-each loop 
// #include<iostream>
// using namespace std;
// int main(){
//   string str ="shashwat saxena";
//   // for(int i=0; i<str.length(); i++){
//   //   cout << str[i] << endl;
//   // }
//   // cout << "\n";
//   //2nd method:
//   for(char ch: str ){
//     cout << ch << endl;
//   }
//   cout << endl;
//   return 0;
// }
//String Member Functions ?
// #include<iostream>
// #include<string>
// using namespace std;
// int main(){
//   string str = "helloworld I Love Coding c++ and c++";
//   cout << str.length() << endl;
//   cout << str[2] << endl;
//   cout << str.at(2) << endl;tr2
//   cout << str.substr(5,5) << endl;
//   cout << str.find("c++", 20) << endl;
//   return 0;
// }
//q4) Valid Anagram ?
// #include <iostream>
// #include<string>
// using namespace std;

// bool isAnagram(string str1, string str2){
//   if (str1.length() != str2.length()) {
//     return false;
//   }
//   int count[26] = {0};
//   for(int i=0; i<str1.length(); i++){
//     count[str1[i] - 'a']++;
//   }
//   for(int i=0; i<str2.length(); i++){
//     if(count[str2[i] - 'a'] == 0){
//       cout << "not valid anagram" << endl;
//       return false;
//     }
//     count[str2[i] - 'a']--;
//   }
//   cout << "Valid anagram\n";
//   return true;
// }
// int main(){
//   string str1 = "anagram";
//   string str2 = "nagaram";
//   isAnagram(str1, str2);
//   return 0;
// }
//q5)How many times lowercase vowels occured in a string ?
// #include<iostream>
// #include<string>
// using namespace std;

// int lowercase(string str) {
//     int volcount = 0;
//     for (int i = 0; i < str.length(); i++) {
//         char ch = tolower(str[i]);
//         if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
//             volcount++;
//         }
//     }
//     return volcount;
// }

// int main() {
//     string str;
//     cout << "Enter a string: ";
//     getline(cin, str);
//     int vowelCount = lowercase(str);
//     cout << "Number of vowels: " << vowelCount << endl;
//     return 0;
// }
//q6). The goal is to determine if you can make s1 equal to s2 by swapping at most one pair of characters in one of the strings
// #include <iostream>
// #include <string>
// using namespace std;

// // Function to check if two strings can be made equal by at most one swap
// bool areAlmostEqual(string s1, string s2) {
//     // If lengths are not equal, return false
//     if (s1.length() != s2.length()) {
//         return false;
//     }

//     // Variables to store differing characters and count of differences
//     char diffChar1, diffChar2;
//     int diff = 0;

//     // Iterate through both strings
//     for (int i = 0; i < s1.length(); i++) {
//         if (s1[i] != s2[i]) {
//             // If it's the first difference, store the characters
//             if (diff == 0) {
//                 diffChar1 = s1[i];
//                 diffChar2 = s2[i];
//             } else {
//                 // If it's the second difference, check if they can be swapped
//                 if (s1[i] != diffChar2 || s2[i] != diffChar1) {
//                     return false;
//                 }
//             }
//             diff++;
//         }
//         // If more than 2 differences, return false
//         if (diff > 2) {
//             return false;
//         }
//     }

//     // If exactly one difference, return false (one swap can't fix this)
//     if (diff == 1) {
//         return false;
//     }

//     // If no differences or exactly two differences that can be swapped, return true
//     return true;
// }

// int main() {
//     string s1 = "bank";
//     string s2 = "kanb";
//     cout << (areAlmostEqual(s1, s2) ? "true" : "false") << endl;

//     return 0;
// }
