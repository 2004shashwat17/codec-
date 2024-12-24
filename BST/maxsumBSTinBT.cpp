#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

class Solution {
public:
    int maxSumBST(Node* root) {
        int maxSum = 0;
        postOrder(root, maxSum);
        return maxSum;
    }

private:
    struct NodeInfo {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };

    NodeInfo postOrder(Node* root, int& maxSum) {
        if (!root) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        NodeInfo left = postOrder(root->left, maxSum);
        NodeInfo right = postOrder(root->right, maxSum);

        if (left.isBST && right.isBST && root->data > left.maxVal && root->data < right.minVal) {
            int currSum = left.sum + root->data + right.sum;
            maxSum = max(maxSum, currSum);
            return {true, currSum, min(root->data, left.minVal), max(root->data, right.maxVal)};
        }

        return {false, 0, 0, 0};
    }
};

int main() {
    // Create a sample tree
    Node* root = new Node(1);
    root->left = new Node(4);
    root->right = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(2);
    root->right->right = new Node(5);
    root->right->right->left = new Node(4);
    root->right->right->right = new Node(6);

    Solution sol;
    cout << "Maximum Sum BST in Binary Tree: " << sol.maxSumBST(root) << endl;

    return 0;
}
