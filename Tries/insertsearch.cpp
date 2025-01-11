#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node { // O(n * L)
    public:
        unordered_map<char, Node*> children;
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

    void insert(string key) { // O(L)
        Node* temp = root;

        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i]) == 0) {
                temp->children[key[i]] = new Node(); // Insert
            }
            temp = temp->children[key[i]];
        }
        temp->endOFWord = true;
    }

    bool Search(string key) { // O(L)
        Node* temp = root;

        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i]) == 0) {
                return false; // Character not found
            }
            temp = temp->children[key[i]];
        }
        return temp->endOFWord; // Return true if end of word is reached
    }
}; 

int main() {
    vector<string> words = {"the", "a", "there", "their", "any", "there"};
    Trie trie;

    for (int i = 0; i < words.size(); i++) {
        trie.insert(words[i]);
    }

    cout << trie.Search("their") << endl; // Output: 1
    cout << trie.Search("the") << endl;  // Output: 1
    cout << trie.Search("these") << endl; // Output: 0
    return 0;
}
 