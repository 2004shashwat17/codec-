#include <iostream>
#include <vector>
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

// Function for inorder traversal to convert BST into a sorted array
void inorderTraversal(Node* root, vector<int>& arr) {
    if (!root) {
        return;
    }
    inorderTraversal(root->left, arr);
    arr.push_back(root->data);
    inorderTraversal(root->right, arr);
}

// Function to find all pairs with the given target sum
vector<pair<int, int>> findTargetSumPairs(Node* root1, Node* root2, int target) {
    vector<int> arr1, arr2;

    // Convert both BST's to sorted arrays
    inorderTraversal(root1, arr1);
    inorderTraversal(root2, arr2);

    // 2-pointers technique to find pairs
    int i = 0, j = arr2.size() - 1;
    vector<pair<int, int>> pairs;

    while (i < arr1.size() && j >= 0) {
        int currSum = arr1[i] + arr2[j];
        if (currSum == target) {
            pairs.push_back({arr1[i], arr2[j]});
            i++;
            j--;
        } else if (currSum < target) {
            i++;
        } else {
            j--;
        }
    }

    return pairs;
}

int main() {
    // Example trees
    Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);
    root1->right->left = new Node(6);
    root1->right->right = new Node(8);

    Node* root2 = new Node(10);
    root2->left = new Node(6);
    root2->right = new Node(15);
    root2->left->left = new Node(3);
    root2->left->right = new Node(8);
    root2->right->left = new Node(11);
    root2->right->right = new Node(18);

    int target = 16;

    // Find and print pairs
    vector<pair<int, int>> result = findTargetSumPairs(root1, root2, target);
    cout << "The pairs are: ";
    for (auto& p : result) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}
