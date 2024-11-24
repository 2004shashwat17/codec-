#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node {
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
    if(nodes[idx] == -1 ) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode-> right = buildTree(nodes);

    return currNode;

}
//Preorder traversal
void preorder(Node* root){ //0(n)
    if(root == NULL){
        return;
    }
    cout << root->data << endl;
    preorder(root -> left);
    preorder(root -> right);
}
//Inorder traversal
void inorder(Node* root){ //0(n) 
    if( root == NULL){
        return;
    }
    inorder(root -> left);
    cout << root->data << endl;
    inorder(root -> right);
}
//Postorder traversal
void postorder(Node* root){ //0(n)
    if( root == NULL){
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    cout << root->data << " ";
}

void levelOrder(Node* root) { // O(n)
    if (root == NULL) {
        return;
    }

    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);

    while (!Q.empty()) {
        Node* curr = Q.front();
        Q.pop();

        if (curr == NULL) {
            cout << endl;  // Newline to indicate end of level
            if (Q.empty()) {
                break;
            }
            Q.push(NULL); // Add a marker for the next level
        } else {
            cout << curr->data << " ";

            if (curr->left != NULL) {
                Q.push(curr->left);
            }
            if (curr->right != NULL) {  // Check and push the right child
                Q.push(curr->right);
            }
        }
    }
}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    // cout << "root = "<< root->data << endl;

    // preorder(root);
    // cout << endl;

    // inorder(root);
    // cout << endl;

    // postorder(root);
    // cout << endl;
    levelOrder(root);
    return 0;
}