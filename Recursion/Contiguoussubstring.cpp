 //We are given a string S, we need to find the count of all contiguous substrings starting and ending with the same character.
  #include<iostream>
  #include <string>
  using namespace std;
  int countsubstring(string str, int i , int j, int n){
        if(n==1){
            return 1;
        } if( n <=0){
            return 0;
        }
        int res = countsubstring(str, i+1, j, n-1) + 
        countsubstring(str, i,j-1,n-1)
         - countsubstring(str,i+1,j-1,n-2);
         if(str[i] == str[j]){
            res ++;
         }
         return res;
    }
  int main(){
    string str = "abcab";
    int n = str.size();
    cout << countsubstring (str, 0, n-1,n) << endl;
    return 0;
  }