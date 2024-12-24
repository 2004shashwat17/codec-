#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            left = right = NULL;
        }    
};

// Preorder Traversal
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";  // Print the node data
    preorder(root->left);
    preorder(root->right);
}

// Helper function to create BST from a sorted vector
Node* BSTfromSortedVec(vector<int>& arr, int st, int end){
        if(st > end){
            return NULL;
        }
        int mid = st + (end - st) / 2;
        Node* curr = new Node(arr[mid]);

        // Recursively create left and right subtrees
        curr->left = BSTfromSortedVec(arr, st, mid - 1);
        curr->right = BSTfromSortedVec(arr, mid + 1, end);

        return curr;
}

// Helper function to perform inorder traversal and store result in nodes vector
void getInorder(Node* root, vector<int>& nodes){
    if(root == NULL){
        return;
    }
    getInorder(root->left, nodes);
    nodes.push_back(root->data);
    getInorder(root->right, nodes);
}

// Function to merge two BSTs into a single BST
Node* mergeBSTs(Node* root1, Node* root2) {
    vector<int> nodes1;
    vector<int> nodes2;
    vector<int> merged;

    // Get inorder traversal of both BSTs
    getInorder(root1, nodes1);
    getInorder(root2, nodes2);

    // Merge the two sorted arrays
    int i = 0, j = 0;
    while(i < nodes1.size() && j < nodes2.size()) {
        if(nodes1[i] < nodes2[j]) {
            merged.push_back(nodes1[i++]);
        } else {
            merged.push_back(nodes2[j++]);
        }
    }
    while(i < nodes1.size()){
        merged.push_back(nodes1[i++]);
    }
    while(j < nodes2.size()){
        merged.push_back(nodes2[j++]);
    }

    // Construct and return the merged BST
    return BSTfromSortedVec(merged, 0, merged.size() - 1);
}

int main(){
    // Creating first BST
    Node* root1 = new Node(2);
    root1->left = new Node(1); 
    root1->right = new Node(4);

    // Creating second BST
    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    // Merging the BSTs
    Node* root = mergeBSTs(root1, root2);

    // Printing the preorder traversal of the merged BST
    preorder(root);
    cout << endl;

    return 0;
}
