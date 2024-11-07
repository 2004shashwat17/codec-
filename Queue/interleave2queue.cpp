#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int> &org) { //0(n)
    int n = org.size();
    queue<int> first;

    // Move the first half of elements to 'first' queue
    for(int i = 0; i < n / 2; i++) {
        first.push(org.front());
        org.pop();
    }

    // Interleave the elements of 'first' and 'org'
    while(!first.empty()) {
        org.push(first.front());
        first.pop();

        org.push(org.front());
        org.pop();
    }
}

int main() {
    queue<int> org;
    for(int i = 1; i <= 10; i++) {
        org.push(i);
    }
    
    interleave(org);

    // Output the interleaved queue
    while(!org.empty()) {
        cout << org.front() << endl;
        org.pop();
    }

    return 0;
}
