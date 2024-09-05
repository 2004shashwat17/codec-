//q5)How many times lowercase vowels occured in a string ?
#include<iostream>
#include<string>
using namespace std;

int lowercase(string str) {
    int volcount = 0;
    for (int i = 0; i < str.length(); i++) {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            volcount++;
        }
    }
    return volcount;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    int vowelCount = lowercase(str);
    cout << "Number of vowels: " << vowelCount << endl;
    return 0;
}