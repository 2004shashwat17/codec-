//q6). The goal is to determine if you can make s1 equal to s2 by swapping at most one pair of characters in one of the strings
#include <iostream>
#include <string>
using namespace std;

// Function to check if two strings can be made equal by at most one swap
bool areAlmostEqual(string s1, string s2) {
    // If lengths are not equal, return false
    if (s1.length() != s2.length()) {
        return false;
    }

    // Variables to store differing characters and count of differences
    char diffChar1, diffChar2;
    int diff = 0;

    // Iterate through both strings
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            // If it's the first difference, store the characters
            if (diff == 0) {
                diffChar1 = s1[i];
                diffChar2 = s2[i];
            } else {
                // If it's the second difference, check if they can be swapped
                if (s1[i] != diffChar2 || s2[i] != diffChar1) {
                    return false;
                }
            }
            diff++;
        }
        // If more than 2 differences, return false
        if (diff > 2) {
            return false;
        }
    }

    // If exactly one difference, return false (one swap can't fix this)
    if (diff == 1) {
        return false;
    }

    // If no differences or exactly two differences that can be swapped, return true
    return true;
}

int main() {
    string s1 = "bank";
    string s2 = "kanb";
    cout << (areAlmostEqual(s1, s2) ? "true" : "false") << endl;

    return 0;
}