#include <iostream>
#include <string>
using namespace std;

// Function to generate permutations of the given string
void permutations(string str, string ans) {
    // If the string is empty, print the permutation
    if (str.empty()) {
        cout << ans << "\n";
        return;
    }
    
    // Iterate through each character in the string
    for (int i = 0; i < str.size(); i++) {
        // Choose the current character
        char ch = str[i];
        
        // Form the remaining string without the current character
        string nextstr = str.substr(0, i) + str.substr(i + 1);
        
        // Recursively generate permutations with the remaining string
        permutations(nextstr, ans + ch);
    }
}

int main() {
    string str = "abc"; // Input string
    string ans = ""; // Initial empty permutation
    
    permutations(str, ans); // Generate and print all permutations
    
    return 0;
}
