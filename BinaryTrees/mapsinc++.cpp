#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
    map<int, string> m; //Creating A Map

    m[101] = "rahul"; //Insert In A Map
    m[110] = "neha";
    m[131] = "rahul";

    cout << m[101];  // Acess Value using key;
    cout << m.count(101) << endl; // 1 if key present, 0 if key not present
    //Automatically set iterator type
    for(auto it : m){ 
        cout << "double = " << it.first * 2 << endl;
    }
    return 0;
}