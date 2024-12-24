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
int rangesumBST(Node* root, int low, int high){
    if(root == NULL){
        return 0;
    }
    int sum = 0;

    if( root->data >= low && root->data <= high ){
        sum += root->data;
    }
    if( root->data > low){
        sum += rangesumBST(root->left, low, high);
    }
    if( root->data < high){
        sum += rangesumBST(root->right, low, high);
    }
    return sum;
}
int main(){
    // Example Tree: [10, 5, 15, 3, 7, null, 18]
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);

    int low = 7, high = 15;
    
    int result = rangesumBST(root, low, high);
    cout << "Sum of nodes in range [" << low << " ," << high << "] is: " << result << endl;
    return 0;
}