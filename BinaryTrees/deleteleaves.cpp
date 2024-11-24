#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Function to remove leaf nodes with the target value
Node* removeLeafNodes(Node* root, int target) {
    if (!root) {
        return nullptr;
    }

    // Recursively remove leaf nodes in left and right subtrees
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);

    // If the current node is a leaf and matches the target value, delete it
    if (!root->left && !root->right && root->data == target) {
        delete root; // Free memory
        return nullptr;
    }

    return root;
}

// Function to build a binary tree from a vector
Node* buildTree(vector<int>& nodes, int& idx) {
    if (idx >= nodes.size() || nodes[idx] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    idx++; // Increment index
    currNode->left = buildTree(nodes, idx);
    idx++; // Increment index
    currNode->right = buildTree(nodes, idx);

    return currNode;
}

// Function to print the tree in a level-order traversal
void printTree(Node* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    vector<int> nodes = {1, 2, 3, 2, -1, 2, 4};
    int idx = 0; // Initialize index for tree construction

    // Build the tree
    Node* root = buildTree(nodes, idx);

    cout << "Original Tree: ";
    printTree(root);
    cout << endl;

    // Remove leaf nodes with target value
    int target = 2;
    root = removeLeafNodes(root, target);

    cout << "Tree after removing leaf nodes with value " << target << ": ";
    printTree(root);
    cout << endl;

    return 0;
}
