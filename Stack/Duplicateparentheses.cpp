#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool isDuplicate(string str){ // O(n)
    stack<char> s;

    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];

        if(ch != ')') {  // If not a closing parenthesis, push onto the stack
            s.push(ch);
        } else { // If it's a closing parenthesis
            if(s.top() == '(') {
                return true; // Found a duplicate pair of parentheses
            }

            // Pop everything till we find the matching opening parenthesis
            while(s.top() != '(') {
                s.pop();
            }
            s.pop(); // Pop the opening parenthesis
        }
    }
    return false; // No duplicates found
}

int main(){
    string str1 = "((a+b))";     // No duplicate parentheses, should return false
    string str2 = "((a+b)+(c+d))"; // Duplicate parentheses around (a+b), should return true

    cout << isDuplicate(str1) << endl; // Output: 0 (false)
    cout << isDuplicate(str2) << endl; // Output: 1 (true)
    return 0;
}
