#include <iostream>
#include <queue>
using namespace std;

void nonrepeating(string str) { // Time: O(n), Space: O(n)
    queue<char> q;
    int freq[26] = {0}; //'a' - 'z'

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        q.push(ch);
        freq[ch - 'a']++;

        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }
        
        if (q.empty()) {
            cout << "-1\n";
        } else {
            cout << q.front() << "\n"; // answer
        }
    }
}

int main() {
    string str = "aabccxb";
    nonrepeating(str);
    return 0;
}
