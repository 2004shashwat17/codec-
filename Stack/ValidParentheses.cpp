#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool isValid(string str){ // O(n)
    stack<char> s;

    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];

        // Push opening brackets onto the stack
        if(ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        } 
        // If it's a closing bracket, check for matching opening bracket
        else {
            if(s.empty()) {
                return false; // If stack is empty, it's invalid
            }

            char top = s.top();
            // Check if the top of the stack matches the closing bracket
            if((top == '(' && ch == ')') ||
               (top == '[' && ch == ']') ||
               (top == '{' && ch == '}')) {
                s.pop(); // Pop if they match
            } else {
                return false; // Mismatch in brackets
            }
        }
    }

    // If stack is empty, the string is valid
    return s.empty();
}

int main(){
    string str1 = "([}])";   // Invalid: false
    string str2 = "([{}])";  // Valid: true

    cout << isValid(str1) << endl; // Output: 0 (false)
    cout << isValid(str2) << endl; // Output: 1 (true)
    return 0;
}
