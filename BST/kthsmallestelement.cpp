#include <iostream>
using namespace std;

class Node {
public: 
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        left = right = nullptr;
    }
};  

class Solution {
public:
    int kthSmallest(Node* root, int k) {
        int count = 0;
        int result = -1;

        inOrderTraversal(root, k, count, result);
        return result;
    }

private:
    void inOrderTraversal(Node* root, int k, int& count, int& result) {
        if (!root) {
            return;
        }
        inOrderTraversal(root->left, k, count, result);
        count++;
        if (count == k) {
            result = root->data;
            return;
        }
        inOrderTraversal(root->right, k, count, result);
    }
};

int main() {
    // Create a sample BST
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);

    Solution sol;
    int k = 3;
    cout << "The " << k << "rd smallest element in the BST is: " << sol.kthSmallest(root, k) << endl;

    return 0;
}
