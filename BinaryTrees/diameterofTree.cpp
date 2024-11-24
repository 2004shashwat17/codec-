#include <iostream>
#include <vector>
#include <algorithm> // For std::max
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

static int idx = -1;

// Function to build the binary tree
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

// Function to calculate the height of the tree
int height(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    return max(leftHt, rightHt) + 1;
}

// Function to calculate the diameter of the tree
int diam1(Node* root) { //0(n^2)
    if (root == NULL) {
        return 0;
    }

    int currDiam = height(root->left) + height(root->right) + 1; // Count nodes in the path
    int leftDiam = diam1(root->left);
    int rightDiam = diam1(root->right);

    return max(currDiam, max(leftDiam, rightDiam)); // Use std::max twice
}

pair<int,int> diam2(Node* root){
    if(root == NULL){
        return make_pair(0,0);
    }
    pair<int, int> leftInfo = diam2(root->left);
    pair<int, int> rightInfo = diam2(root -> right);

    int currDaim = leftInfo.second + rightInfo.second + 1;
    int finalDaim  = max(currDaim, max(leftInfo.first, rightInfo.first));
    int finalHt = max(leftInfo.second, rightInfo.second) + 1;

    return make_pair(finalDaim , finalHt);
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    idx = -1; // Reset idx before building the tree
    Node* root = buildTree(nodes);

    cout << "Diameter: " << diam2(root).first << endl;
    return 0;
}
