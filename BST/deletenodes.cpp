#include<iostream>
using namespace std;

class Node {
public:
    int data;      // Public access
    Node* left;    // Public access
    Node* right;   // Public access

    // Constructor
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Function to insert a value into the BST
Node* insert(Node* root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return root;
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Function to build a BST from an array
Node* buildBST(int arr[], int n) {
    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

// Function to perform inorder traversal and print the BST
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " "; // Print data in the inorder sequence
    inorder(root->right);
}


Node* getInorderSuccessor(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root; //IS
}
Node* delNode (Node* root, int val){
    if(root == NULL){
        return NULL;
    }
    if(val < root->data){ //left subtree
        root->left = delNode(root->left, val);
    } else if(val > root->data){ // right subtree
        root->right = delNode(root->right, val);
    } else {
        //root == val
        //case1 : 0 children
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //case2 : 1 child
        if(root->left == NULL || root->right == NULL){
            return root->left == NULL ? root->right : root->left;
        }
        //case 3 : 2 children
        Node* IS = getInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = delNode(root->right, IS->data);
        return root;
    }
    return root;
}
int main() {
    int arr[6] = {5, 1, 3, 4, 2, 7};

    Node* root = buildBST(arr, 6);  
    inorder(root);
    cout << endl;

    delNode(root, 4);
    inorder(root);
    cout << endl;
    return 0;
}
