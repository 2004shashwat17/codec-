#include<iostream>
#include<string>
using namespace std;

int balancedStringSplit(string s){
    int countL = 0; // Counter for 'L'
    int countR = 0; // Counter for 'R'
    int result = 0; // To store the no. of balanaced strings

    // Iterate through each character in the string
    for(char c : s){
        if( c == 'L'){
            countL++;
        } else if (c == 'R'){
            countR++;
        }

    // Whenever 'L' and 'R' counts are equal, it's a balanced substring
    if(countL == countR){
        result++;
        countL = 0; // Reset the count of 'L'
        countR = 0; // Reset the count of 'R'
    }
    }
    return result;
}

int main(){
     // You can modify this string to test with different inputs
    string s = "RLRRLLRLRL";

    cout << "Input String : " << s << endl;
    cout << " Max Balanced Substring : " << balancedStringSplit(s) << endl;

    return 0;
}