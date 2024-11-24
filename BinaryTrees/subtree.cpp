#include <iostream>
#include <vector>
using namespace std;

// Define the index for the buildTree function
int idx = -1;

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

// Function to build the tree from a vector
Node* buildTree(vector<int>& nodes) {
    idx++;
    if (nodes[idx] == -1) {
        return NULL;
    }
    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);
    return currNode;
}

// Function to check if two trees are identical
bool isIdentical(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    if (root1->data != root2->data) {
        return false;
    }
    return isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

// Function to check if subRoot is a subtree of root
bool isSubtree(Node* root, Node* subRoot) {
    if (root == NULL) {
        return false;
    }
    if (isIdentical(root, subRoot)) {
        return true;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    // Constructing the subRoot manually
    Node* subRoot = new Node(2);
    subRoot->left = new Node(4);
    subRoot->right = new Node(5);

    // Check if subRoot is a subtree of root
    cout << isSubtree(root, subRoot) << endl; // Output: 1
    return 0;
}
