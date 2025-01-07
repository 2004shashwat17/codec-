#include<iostream>
#include <vector>
#include<queue>
#include<map>
using namespace std;

int idx = -1;

class Node{
public:    
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* buildTree(vector<int>& nodes){
    idx++;
    if (nodes[idx] == -1) {
        return NULL;
    }
    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);
    return currNode;
}

void bottomView(Node* root) {
    queue<pair<Node* , int>> Q;
    map<int,int> m;

    Q.push(make_pair(root, 0));
    while(!Q.empty()){
        pair<Node*, int> curr = Q.front();
        Q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;

        m[currHD] = currNode->data;
        if(currNode->left != NULL) {
            Q.push(make_pair(currNode->left, currHD - 1));
        }
        if(currNode->right != NULL){
            Q.push(make_pair(currNode->right, currHD + 1));
        }
    }
    for(auto it : m){
        cout << it.second << " ";
    }
    cout << endl;
}
int main(){
    vector<int> nodes = {20,8,5,-1,-1,3,10,-1,-1,14,-1,-1,22,-1,25,-1,-1};

    Node* root =  buildTree(nodes);
    cout << "Bottom View: ";
    bottomView(root);
    return 0;
}