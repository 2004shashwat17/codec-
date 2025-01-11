#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node{
    public:
        unordered_map<char,Node*> children;
        bool endOFWord;

        Node() {
            endOFWord = false;
        }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }    

    void insert(string key) {
        Node* temp = root;

        for(int i = 0; i < key.size(); i++) {
            if(temp->children.count(key[i]) == 0) {
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->endOFWord = true;
    }

    bool Search(string key) {
        Node* temp = root;
        for(int i = 0; i < key.size(); i++) {
            if(temp->children.count(key[i]) == 0) {
                return false;
            }
            temp = temp->children[key[i]];
        }
        return temp->endOFWord;
    }

    void longestHelper(Node* root, string &ans, string temp) {
        for(pair<char, Node*> child : root->children) {
            if(child.second->endOFWord) {
                temp += child.first;

                if((temp.size() == ans.size() && temp < ans) || (temp.size() > ans.size())) {
                    ans = temp;
                }

                // Recurse on the child node
                longestHelper(child.second, ans, temp);
                temp.pop_back();  // Backtrack
            }
        }
    }

    string longestStringWithEOL() {
        string ans = "";
        longestHelper(root, ans, "");
        return ans;
    }
};

string longestString(vector<string> dict) {
    Trie trie;

    for(int i = 0; i < dict.size(); i++) {
        trie.insert(dict[i]);
    }
    return trie.longestStringWithEOL();
}

int main() {
    vector<string> dict = {"a", "banana", "app", "appl", "ap", "apply", "apple"};

    cout << longestString(dict) << endl;
    return 0;
}
