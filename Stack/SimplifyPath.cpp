#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string simplifyPath(string path) {
    vector<string> stack;
    stringstream ss(path);
    string token;
    
    // Split the path by '/'
    while (getline(ss, token, '/')) {
        if (token == "" || token == ".") {
            // Ignore empty or current directory symbol ('.')
            continue;
        } else if (token == "..") {
            // Go back to the parent directory, pop from stack if possible
            if (!stack.empty()) {
                stack.pop_back();
            }
        } else {
            // Push valid directory names to the stack
            stack.push_back(token);
        }
    }
    
    // Rebuild the canonical path from the stack
    string result = "/";
    for (int i = 0; i < stack.size(); i++) {
        result += stack[i];
        if (i != stack.size() - 1) {
            result += "/";
        }
    }
    
    return result;
}

int main() {
    // Test cases
    string path1 = "/home/";
    string path2 = "/home//foo/";
    string path3 = "/home/user/Documents/../Pictures";
    string path4 = "/../";
    string path5 = "/.../a/../b/c/../d/./";
    
    cout << "Simplified Path 1: " << simplifyPath(path1) << endl;
    cout << "Simplified Path 2: " << simplifyPath(path2) << endl;
    cout << "Simplified Path 3: " << simplifyPath(path3) << endl;
    cout << "Simplified Path 4: " << simplifyPath(path4) << endl;
    cout << "Simplified Path 5: " << simplifyPath(path5) << endl;

    return 0;
}
