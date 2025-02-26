#include <iostream>
#include <string>
using namespace std;

void permutations(string str, string ans) {
    int n = str.size();
    if(n == 0){
        cout << ans << "\n";
        return;
    }    
    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        string nextstr = str.substr(0, i) + str.substr(i + 1, n-i-1);
        permutations(nextstr, ans + ch);
    }
}

int main() {
    string str = "abc"; // Input string
    string ans = ""; // Initial empty permutation
    
    permutations(str, ans); // Generate and print all permutations
    
    return 0;
}
