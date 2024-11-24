#include<iostream>
#include<vector>
using namespace std;
int idx = -1;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* buildtree(vector<int>& nodes){
    idx++;
    if(nodes[idx] == -1){
        return NULL;
    }
    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildtree(nodes);
    currNode->right = buildtree(nodes);
    return currNode;
}

// approach 1 -> 0(n) ; 0(n)
bool rootToNodePath(Node* root, int n, vector<int> &path){
    if(root == NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data == n){
        return true;
    } 

    int isLeft = rootToNodePath(root->left, n, path);
    int isRight = rootToNodePath(root->right, n, path);

    if(isLeft || isRight){
        return true;
    }

    path.pop_back();
    return false;
}
int LCA(Node* root, int n1, int n2){
    vector<int> path1;
    vector<int> path2;

    rootToNodePath(root, n1, path1);
    rootToNodePath(root, n2, path2);

    int lca = -1;
    for(int i=0, j=0; i<path1.size()&& j<path2.size(); i++,j++ ){
        if(path1[i] != path2[j]) {
            return lca;
        }
        lca = path1[i];
    }

    return lca;
}

// approach 2 -> 0(n) ; 0(1)
Node* LCA2(Node* root, int n1, int n2){//0(n), 0(1)
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node* leftLCA = LCA2(root->left, n1, n2);
    Node* rightLCA = LCA2(root->right, n1, n2);

    if(leftLCA != NULL && rightLCA != NULL){
        return root;
    } 

    return leftLCA == NULL ? rightLCA : leftLCA;
}


int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildtree(nodes);

    int n1 = 4, n2 = 5;
    // cout << "lca = " << LCA(root, n1, n2) << endl;  
    cout << "lca2 = " << LCA2(root, n1, n2)->data << endl; 
    return 0;
}