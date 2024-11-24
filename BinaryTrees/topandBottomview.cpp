#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

// Function to print the top view of the tree
void topView(Node* root) {
    queue<pair<Node*, int>> Q;
    map<int, int> m;

    Q.push(make_pair(root, 0));
    while (!Q.empty()) {
        pair<Node*, int> curr = Q.front();
        Q.pop();

        Node* currNode = curr.first;  // Current node
        int currHD = curr.second;     // Horizontal distance

        // If this horizontal distance is not yet in the map, add it
        if (m.count(currHD) == 0) {  // HD -> add in map
            m[currHD] = currNode->data;
        }

        // Add the left child to the queue with horizontal distance -1
        if (currNode->left != NULL) {
            Q.push(make_pair(currNode->left, currHD - 1));
        }
        // Add the right child to the queue with horizontal distance +1
        if (currNode->right != NULL) {
            Q.push(make_pair(currNode->right, currHD + 1));
        }
    }

    // Print the nodes in the top view in order of their horizontal distances
    for (auto it : m) {
        cout << it.second << " ";
    }
    cout << endl;
}

// Function to print the bottom view of the tree
void bottomView(Node* root) {
    queue<pair<Node*, int>> Q;
    map<int, int> m;

    Q.push(make_pair(root, 0));
    while (!Q.empty()) {
        pair<Node*, int> curr = Q.front();
        Q.pop();

        Node* currNode = curr.first;  // Current node
        int currHD = curr.second;     // Horizontal distance

        // Overwrite the value at this horizontal distance
        m[currHD] = currNode->data;

        // Add the left child to the queue with horizontal distance -1
        if (currNode->left != NULL) {
            Q.push(make_pair(currNode->left, currHD - 1));
        }
        // Add the right child to the queue with horizontal distance +1
        if (currNode->right != NULL) {
            Q.push(make_pair(currNode->right, currHD + 1));
        }
    }

    // Print the nodes in the bottom view in order of their horizontal distances
    for (auto it : m) {
        cout << it.second << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    cout << "Top View: ";
    topView(root);

    cout << "Bottom View: ";
    bottomView(root);

    return 0;
}
