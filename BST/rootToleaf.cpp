#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public :
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            left = right = NULL;
        }
};

//Function to insert a value into the BST
Node* insert(Node* root, int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }

    if(val < root->data){
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

Node* buildBST(int arr[], int n){
    Node* root = NULL;

    for(int i=0; i<n; i++){
        root = insert(root, arr[i]);
    }
    return root;
}

void printPath(vector<int> path){
    cout << "path : ";
    for(int i=0; i<path.size(); i++){
        cout << path[i] << " ";
    }
    cout << endl;
}

void pathHelper(Node* root, vector<int> &path) {
    if(root == NULL){
        return;
    }
    path.push_back(root->data);

    if(root->left == NULL && root->right == NULL){
        printPath(path);
        path.pop_back();
        return;
    }

    pathHelper(root->left , path);
    pathHelper(root->right, path);

    path.pop_back();
}

void rootToLeafPath(Node* root){
    vector<int> path;
    pathHelper(root, path); 
}

int main(){
    int arr[6] = {5,1,3,4,2,7};
    Node* root = buildBST(arr, 6);

    rootToLeafPath(root);
    return 0;
}