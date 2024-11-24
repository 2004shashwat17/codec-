#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Node{
    public:
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
// recursive approach
Node* invertTree(Node* root){
    if(!root){
        return nullptr;
    }

    //swap left and right node
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}
// using level order :
Node* invert(Node*  root){
    if(!root){
        return nullptr;
    }
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();

        Node* temp = root->left;
        current-> left = current -> right;
        current->right = temp;

        if(current->left){
            q.push(current->left);
        }
        if(current->right){
            q.push(current->right);
        }
    }
    return root;
}
// Function to perform level-order traversal and print the tree
void printLevelOrder(Node* root) {
    if (!root) {
        cout << "Tree is empty" << endl;
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        }
    }
    cout << endl;
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    idx = -1; // Reset index for tree building
    Node* root = buildTree(nodes);

      cout << "Original Tree (Level-Order): ";
    printLevelOrder(root);

    // Invert the tree using recursive function
    root = invertTree(root);
    cout << "Inverted Tree (Recursive) (Level-Order): ";
    printLevelOrder(root);
    // Rebuild the tree for iterative testing
    idx = -1;
    root = buildTree(nodes);

    // Invert the tree using iterative function
    root = invert(root);
    cout << "Inverted Tree (Iterative) (Level-Order): ";
    printLevelOrder(root);
    return 0;
}