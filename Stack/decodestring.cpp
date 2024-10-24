#include <iostream>
#include <stack>
#include <string>
using namespace std;
string decode(string s){
    stack<int> st;
    stack<string> st1;
    string sb;
    int n = 0;

    for (char c : s){
        if(isdigit(c)) {
           n = n * 10 + (c - '0');//3
        } else if (c == '[') {
            st.push(n);
            n = 0;

            st1.push(sb);
            sb = " ";
        } else if (c == ']'){
            int k = st.top();
            st.pop();
            string temp = sb;
            sb = st1.top();
            st1.pop();
            while( k-- > 0 ) {
                sb += temp;
            }
        } else {
            sb += c;
        }
    }
    return sb;
}  
int main(){
    string s1 = "3[a]2[bc]";
    cout << "Decoded string of " << s1 << ":" << decode(s1) << endl;

    string s2 = "2[abc]3[cd]ef";
    cout << "Decoded string of " << s2 <<":"<< decode(s2) << endl;

    return 0;
}
