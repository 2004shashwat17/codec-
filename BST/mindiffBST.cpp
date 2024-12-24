#include<iostream>
#include<climits>
#include<cmath>
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

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void findClosest(Node* root, int K, int& closest, int& minDiff) {
    if (root == nullptr) {
        return;
    }
    int diff = abs(root->data - K);

    if (diff < minDiff) {
        minDiff = diff;
        closest = root->data;
    }

    if (K < root->data) {
        findClosest(root->left, K, closest, minDiff);
    } else {
        findClosest(root->right, K, closest, minDiff);
    }
}

int main() {
    Node* root = nullptr;

    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 11);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 20);

    int K1 = 5;
    int closest1 = -1;
    int minDiff1 = INT_MAX;
    findClosest(root, K1, closest1, minDiff1);
    cout << "Closest to " << K1 << " is: " << closest1 << " (abs diff = " << minDiff1 << ")" << endl;

    int K2 = 19;
    int closest2 = -1;
    int minDiff2 = INT_MAX;
    findClosest(root, K2, closest2, minDiff2);
    cout << "Closest to " << K2 << " is: " << closest2 << " (abs diff = " << minDiff2 << ")" << endl;

    return 0;
}
