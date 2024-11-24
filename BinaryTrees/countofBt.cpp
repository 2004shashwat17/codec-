#include<iostream>
#include<vector>
using namespace std;
class Node{
    public :
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            left = right = NULL;
        }
};
static int idx = -1;

Node* buildTree(vector<int> nodes){
    idx++;
    if(nodes[idx] == -1){
        return NULL;
    }
    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

int count(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftC = count(root -> left);
    int rightC = count(root -> right);
    return leftC + rightC + 1;
}
int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    cout << "count : "<< count(root) << endl;

    Node* root2 = new Node(5);
    root2->left = new Node(3);
    root2->right = new Node(4);

    cout<< "count2 : " << count(root2) << endl;
    return 0;
}