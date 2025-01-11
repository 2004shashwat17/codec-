#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    int freq; // Frequency of words passing through this node

    Node() {
        endOfWord = false;
        freq = 0;
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

        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i]) == 0) {
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
            temp->freq++;
        }

        temp->endOfWord = true;
    }
    
    string getPrefix(string key) {
        Node* temp = root;
        string prefix = "";

        for (int i = 0; i < key.size(); i++) {
            prefix += key[i];
            if (temp->children[key[i]]->freq == 1) {
                break;
            }
            temp = temp->children[key[i]];
        }
        return prefix;
    }
};

void prefixProblem(vector<string> dict) {
    Trie trie;
    for (int i = 0; i < dict.size(); i++) {
        trie.insert(dict[i]);
    }

    for (int i = 0; i < dict.size(); i++) {
        cout << trie.getPrefix(dict[i]) << endl;
    }
}

int main() {
    vector<string> dict = {"zebra", "dog", "duck", "dove"};
    prefixProblem(dict);
    return 0;
}
