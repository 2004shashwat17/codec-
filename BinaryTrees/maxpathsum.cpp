#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
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

// Function to build a tree from a vector
Node* buildTree(vector<int>& nodes, int& idx) {
    if (idx >= nodes.size() || nodes[idx] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    idx++;
    currNode->left = buildTree(nodes, idx);
    idx++;
    currNode->right = buildTree(nodes, idx);

    return currNode;
}

// Function prototype for maxPathDown
int maxPathDown(Node* node, int& maxSum);

// Function to calculate the maximum path sum
int maxPathSum(Node* root) {
    int maxSum = INT_MIN; // Initialize to the smallest integer value
    maxPathDown(root, maxSum); // Calculate the maximum path sum
    return maxSum;
}

// Helper function to calculate max path sum down from a node
int maxPathDown(Node* node, int& maxSum) {
    if (!node) return 0;

    // Recursively calculate the maximum path sum for the left and right subtrees
    int leftMax = max(0, maxPathDown(node->left, maxSum)); // Ignore negative paths
    int rightMax = max(0, maxPathDown(node->right, maxSum)); // Ignore negative paths

    // Update the global maxSum if the current path sum is larger
    maxSum = max(maxSum, leftMax + rightMax + node->data);

    // Return the maximum sum of the path that can be extended to the parent node
    return node->data + max(leftMax, rightMax);
}

int main() {
    vector<int> nodes = {1, 2, 3, 4, -1, 2, -1, -1, 4, -1, -1};
    int idx = 0; // Start index for building the tree
    Node* root = buildTree(nodes, idx);

    // Calculate and print the maximum path sum
    cout << "Maximum Path Sum: " << maxPathSum(root) << endl;

    return 0;
}
