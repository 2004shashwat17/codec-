#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
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

// Helper function to build the binary tree.
Node* buildTree(vector<int>& nodes, int& idx) {
    if (idx >= nodes.size() || nodes[idx] == -1) {
        idx++;
        return NULL;
    }

    Node* currNode = new Node(nodes[idx++]);
    currNode->left = buildTree(nodes, idx);
    currNode->right = buildTree(nodes, idx);

    return currNode;
}

// Helper function to check if the tree is uni-valued.
bool isunivHelper(Node* node, int val) {
    if (!node) {
        return true;
    }
    if (node->data != val) {
        return false;
    }
    return isunivHelper(node->left, val) && isunivHelper(node->right, val);
}

// Function to check if the binary tree is uni-valued.
bool isUnivalTree(Node* root) {
    if (!root) {
        return true;
    }
    return isunivHelper(root, root->data);
}

int main() {
    vector<int> nodes = {1, 1, 1, 1, 1, -1, 1}; // Input for the binary tree (preorder with -1 as NULL).
    int idx = 0; // Index to track position in the vector during tree construction.
    Node* root = buildTree(nodes, idx);

    // Check if the tree is uni-valued and output the result.
    bool result = isUnivalTree(root);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
