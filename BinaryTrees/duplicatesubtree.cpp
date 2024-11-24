#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
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

// Serialize subtrees and find duplicates
string serialize(Node* node, unordered_map<string, int>& subtreeMap, vector<Node*>& duplicates) {
    if (!node) {
        return "#"; // Null nodes are represented by "#"
    }

    // Serialize the current subtree
    string left = serialize(node->left, subtreeMap, duplicates);
    string right = serialize(node->right, subtreeMap, duplicates);
    string subtree = to_string(node->data) + "," + left + "," + right;

    // Count occurrences of the serialized subtree
    subtreeMap[subtree]++;
    if (subtreeMap[subtree] == 2) { // Add to duplicates only once
        duplicates.push_back(node);
    }
    return subtree;
}

vector<Node*> findDuplicateSubtrees(Node* root) {
    unordered_map<string, int> subtreeMap; // To count occurrences of each serialized subtree
    vector<Node*> duplicates;             // To store roots of duplicate subtrees
    serialize(root, subtreeMap, duplicates);
    return duplicates;
}

// Function to print duplicate subtree root values
void printDuplicateSubtrees(vector<Node*>& duplicates) {
    cout << "Duplicate Subtree Roots: ";
    for (Node* node : duplicates) {
        cout << node->data << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nodes = {1, 2, 3, 4, -1, 2, 4, -1, -1, 4};
    int idx = 0;

    // Build the tree
    Node* root = buildTree(nodes, idx);

    // Find and print duplicate subtrees
    vector<Node*> duplicates = findDuplicateSubtrees(root);
    printDuplicateSubtrees(duplicates);

    return 0;
}
