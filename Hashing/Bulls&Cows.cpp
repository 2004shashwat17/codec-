#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

string getHint(string secret, string guess) {
    int bulls = 0, cows = 0;
    unordered_map<char, int> secret_count;
    unordered_map<char, int> guess_count;

    // First pass: count bulls and track unmatched characters
    for (int i = 0; i < secret.length(); i++) {
        if (secret[i] == guess[i]) {
            bulls++;
        } else {
            secret_count[secret[i]]++;
            guess_count[guess[i]]++;
        }
    }

    // Second pass: count cows using unmatched characters
    for (auto &entry : guess_count) {
        char digit = entry.first;
        int count = entry.second;
        if (secret_count.count(digit)) {
            cows += min(count, secret_count[digit]);
        }
    }

    return to_string(bulls) + "A" + to_string(cows) + "B";
}

int main() {
    string secret, guess;
    cout << "Enter the secret number: ";
    cin >> secret;
    cout << "Enter the guess: ";
    cin >> guess;

    string result = getHint(secret, guess);
    cout << "Hint: " << result << endl;

    return 0;
}
