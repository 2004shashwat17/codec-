#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    vector<string> anagrams;
};
class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
//Inserts a word into the trie using its sorted character sequence.

    void insert(const string& sortedWord, const string& originalWord) {
        TrieNode* currentNode = root;
        for (char c : sortedWord) {
            if (!currentNode->children.count(c)) {
                currentNode->children[c] = new TrieNode();
            }
            currentNode = currentNode->children[c];
        }
        currentNode->anagrams.push_back(originalWord);
    }
    //Gathers all groups of anagrams stored in the trie.
    void collectAnagrams(TrieNode* node, vector<vector<string>>& result) {
        if (!node) return;
        if (!node->anagrams.empty()) {
            result.push_back(node->anagrams);
        }
        for (auto& child : node->children) {
            collectAnagrams(child.second, result);
        }
    }
    //create a trie, sort the string, insert the sorted string and original string into the trie
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        Trie trie;

        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            trie.insert(sortedStr, str);
        }

        vector<vector<string>> result;
        trie.collectAnagrams(trie.root, result);

        return result;
    }
};  // <-- This closes the class Trie properly.

int main() {
    Trie trie;  // Create an object of the Trie class.

    // Sample Input 1
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result1 = trie.groupAnagrams(strs1);  // Call groupAnagrams using the Trie object.

    cout << "Sample Output 1:" << endl;
    for (const auto& group : result1) {
        cout << "[";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    // Sample Input 2
    vector<string> strs2 = {""};
    vector<vector<string>> result2 = trie.groupAnagrams(strs2);  // Call groupAnagrams using the Trie object.

    cout << "Sample Output 2:" << endl;
    for (const auto& group : result2) {
        cout << "[";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    // Sample Input 3
    vector<string> strs3 = {"a"};
    vector<vector<string>> result3 = trie.groupAnagrams(strs3);  // Call groupAnagrams using the Trie object.

    cout << "Sample Output 3:" << endl;
    for (const auto& group : result3) {
        cout << "[";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}

