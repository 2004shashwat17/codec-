#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(string digits, string output, int index, vector<string>& ans, string mapping[]) {
    // Base case: If index reaches the length of digits, add the output to ans
    if (index >= digits.length()) {
        ans.push_back(output);
        return;
    }

    int number = digits[index] - '0'; // Convert character to integer
    string value = mapping[number];

    for (int i = 0; i < value.length(); i++) {
        output.push_back(value[i]); // Choose a letter
        solve(digits, output, index + 1, ans, mapping); // Recur for next digit
        output.pop_back(); // Backtrack
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;

    // Edge case: If input is empty, return empty result
    if (digits.length() == 0) {
        return ans;
    }

    string output = "";
    int index = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    solve(digits, output, index, ans, mapping);
    return ans;
}

int main() {
    string digits;
    cout << "Enter digits: ";
    cin >> digits;

    vector<string> result = letterCombinations(digits);

    cout << "Letter Combinations: ";
    for (string s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
