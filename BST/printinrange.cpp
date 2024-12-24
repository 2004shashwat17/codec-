#include<iostream>
#include<vector>
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

void printInRange(Node* root, int start, int end){
    if(root == NULL){
        return;
    }
    if(start <= root->data &&  root->data <= end) {
        printInRange(root->left, start, end);
        cout << root->data << " ";
        printInRange(root->right, start, end);
    } else if(root->data < start){
        printInRange(root->right, start, end);
    } else {
        printInRange(root->left, start, end);
    }
}

int main(){
    int arr[6] = {5,1,3,4,2,7};
    Node* root = buildBST(arr, 6);

    printInRange(root, 5, 12);
    return 0;
}