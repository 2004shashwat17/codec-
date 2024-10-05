#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = NULL;
        }
};
class List {
    Node* head;
    Node* tail;
   public:
   List(){
    head = NULL;
    tail = NULL;
   } 

     void push_front(int val) {
        Node* newNode = new Node(val); // dynamic allocation

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }   
    } 
        void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n"; 
    }
    int getsize(){
        int sz = 0;
        Node* temp = head;
        while(temp!=NULL){
            temp=temp->next;
            sz++;
        }
        return sz;
    }

    void removenth(int n){ //0(N)time complexcity ; 0(1)space complexcity
        int size = getsize();
        Node* prev = head;

        for(int i=1; i<(size-n); i++){
            prev = prev->next; 
        }

        Node* toDel = prev->next;
        cout << "going to delete : " << toDel->data << endl;

        prev->next = prev->next->next;
    }
};
int main(){
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList();//1->2->3->4->5->null

    ll.removenth(2);
    ll.printList(); //1->2->3->5->null
    return 0;
}