#include <iostream>
#include <vector>
using namespace std;

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

void kthHelper(Node* root, int K, int currLevel) {
    if (root == NULL) {
        return;
    }
    if (currLevel == K) {
        cout << root->data << " ";
        return;
    }

    kthHelper(root->left, K, currLevel + 1); // Increment the level
    kthHelper(root->right, K, currLevel + 1); // Increment the level
}

void Kthlevel(Node* root, int K) { //0(n)
    kthHelper(root, K, 1); // Start with level 1
    cout << endl;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    Kthlevel(root, 3); // Print nodes at level 3
    return 0;
}
