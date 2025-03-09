#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void reversekElements(queue<int>& q, int K) {
    if(q.empty() || K <= 0 || K > q.size()) {
        return; // Edge cases: empty queue, invalid K
    }
    stack<int> s;

    // Step 1: Dequeue the first K elements and push them onto a stack
    for(int i=0; i < K; i++){
        s.push(q.front());
        q.pop();
    } 
       // Step 2: Pop elements from stack and enqueue them back to the queue
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    // Step 3: Rotate the rest of the elements to the back of the queue
    int size = q.size();
    for (int i = 0; i < size - K; i++) {
        q.push(q.front());
        q.pop();
    }
}
void printQueue(queue<int>& q){
    while(!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
    cout << endl;
}
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int K = 3;
    reversekElements(q, K);

     cout << "Queue after reversing first " << K << " elements: ";
    printQueue(q);
    return 0;
}