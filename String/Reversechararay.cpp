//q2)Reverse An Char Array ?
#include<iostream>
#include<cstring>
using namespace std;

void reverse(char word[], int n) {
    int st = 0, end = n - 1;
    while (st < end) {
        swap(word[st], word[end]);
        st++;
        end--;
    }
}

int main() {
    char word[] = "code"; // Use double quotes for string literals
    reverse(word, strlen(word));
    cout << "reverse = " << word << endl;
    return 0;
}