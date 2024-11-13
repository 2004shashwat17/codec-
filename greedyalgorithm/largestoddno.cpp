#include <iostream>
#include <string>
using namespace std;

string largestOddNumber(string num) {
    string largestOdd = ""; // Variable to store the largest odd number
    
    // Iterate through the string to find the largest odd number
    for (int i = 0; i < num.length(); i++) {
        // If the current character is an odd digit
        if ((num[i] - '0') % 2 != 0) {
            // Update largestOdd with the current substring
            largestOdd = num.substr(0, i + 1);
        }
    }

    return largestOdd; // Return the largest odd number found (if any)
}

int main() {
    string num;
    cin >> num;  // Input string representing the large number
    cout << largestOddNumber(num) << endl;  // Output the result
    return 0;
}
    