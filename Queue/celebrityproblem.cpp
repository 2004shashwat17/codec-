#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        stack<int> s;
        
        for (int i = 0; i < n; i++) {
            s.push(i);
        }

        while (s.size() > 1) {
            int i = s.top();
            s.pop();
            int j = s.top();
            s.pop();
            
            if (mat[i][j] == 1) { 
                s.push(j);
            } else { 
                s.push(i);
            }
        }

        int celeb = s.top();
        s.pop();

        for (int i = 0; i < n; i++) {
            if (i != celeb) {
                if (mat[i][celeb] == 0 || mat[celeb][i] == 1) {
                    return -1;
                }
            }
        }
        
        return celeb;
    }
};

int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;
    while (t--) {
        int n;
        cout << "Enter matrix size: ";
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        cout << "Enter matrix values:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << "Celebrity Index: " << ob.celebrity(M) << endl;
    }
    return 0;
}
