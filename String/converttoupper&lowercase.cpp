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