#include <iostream>
using namespace std;

class Node {
public:
    int data; // Public access
    Node* left;
    Node* right;

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

// Function to search for a key in the BST
bool search(Node* root, int key) {
    if (root == NULL) {
        return false;
    }
    if (root->data == key) {
        return true;
    }
    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Main function
int main() {
    int arr[6] = {5, 1, 3, 4, 2, 7};

    Node* root = buildBST(arr, 6);

    // Searching for a value
    cout << (search(root, 6) ? "Found" : "Not Found") << endl;
    cout << (search(root, 4) ? "Found" : "Not Found") << endl;

    return 0;
}
