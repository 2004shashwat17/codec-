#include<iostream>
#include<list>
using namespace std;

void printList(list<int> ll){
    list<int>::iterator itr;
    for(itr=ll.begin(); itr!=ll.end(); itr++){
        cout << (*itr) << "->"; 
    }
    cout << "NULL" << endl;
}
int main(){
    list<int> ll;

    ll.push_front(2);
    ll.push_front(1); //1->2
    
    ll.push_back(3); //1->2->3
    ll.push_back(4); //1->2->3->4

    printList(ll);
    cout << ll.size() << endl;

    cout << "head = " << ll.front() << "\n";
    cout << "tail = " << ll.back() << "\n";

    //iterator insert(iterator pos, const T& value);
    auto it = ll.begin();
    advance(it ,2); //move iterator to the 3rd position(0-based index)
    ll.insert(it ,5); //insert 5 at 3rd position .
    cout << "After inserting 5 at position 3: ";
    printList(ll); // 1->2->5->3->4->NULL

    ll.pop_front(); 
    printList(ll);
    ll.pop_back();
    printList(ll);
    return 0;
}