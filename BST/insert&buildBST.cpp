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

int main() {
    int arr[6] = {5, 1, 3, 4, 2, 7};

    Node* root = buildBST(arr, 6);
    inorder(root);  // Inorder traversal prints the BST in sorted order
    cout << endl;
    return 0;
}
