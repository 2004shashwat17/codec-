#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Stack {
    vector<T> vec;
public:
    void push(T val) { //0(1)
        vec.push_back(val);
    }    
    void pop(){ //0(1)
        if(isEmpty()) {
            cout << "stack is empty\n";
            return;
        }
        vec.pop_back();
    }

    T top() { //0(1)
         if(isEmpty()) {
            cout << "stack is empty\n";
            return -1;
        }
        int lastidx = vec.size()-1;
        return vec[lastidx];
    }

    bool isEmpty(){ //0(1)
        return vec.size() == 0;
    }
};
int main(){
    Stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    while (!s.isEmpty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}