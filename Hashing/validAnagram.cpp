#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

bool validAnagrams(string s, string t){
    if(s.size() != t.size()){
        return false;
    }
    //s <char, freq>
    unordered_map<char,int> freq;
    for(int i=0; i<s.size(); i++){
        if(freq.count(s[i])) {
            freq[s[i]]++;
        } else {
            freq[s[i]] = 1; 
        }
    }

    //2nd to look for t's chars in freq
    for(int i=0; i<t.size(); i++){
        if(freq.count(t[i])) {
            freq[t[i]]--;
            if(freq[t[i]] == 0){
                freq.erase(t[i]);
            } else {
                return false;
            }
        }
    }
    return freq.size() == 0;
}

int main(){
    string s = "tulip";
    string t = "lipid";

    cout << validAnagrams(s, t) << endl;

    return 0;
}