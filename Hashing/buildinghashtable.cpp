#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val) {
        this->key = key;
        this->val = val;
        next = NULL;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

class HashTable {
    int totSize;
    int currSize;
    Node** table;

    int hashFunction(string key) {
        int idx = 0;
        for (int i = 0; i < key.size(); i++) {
            idx = (idx + (key[i] * key[i])) % totSize;
        }
        return idx % totSize;
    }

    void rehash() {
        Node** oldTable = table;
        int oldSize = totSize;

        totSize = 2 * totSize;
        table = new Node*[totSize];

        for (int i = 0; i < totSize; i++) {
            table[i] = NULL;
        }

        // Copy old values
        for (int i = 0; i < oldSize; i++) {
            Node* temp = oldTable[i];
            while (temp != NULL) {
                insert(temp->key, temp->val);
                temp = temp->next;
            }

            if (oldTable[i] != NULL) {
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }

public:
    HashTable(int size = 5) {
        totSize = size;
        currSize = 0;
        table = new Node*[totSize];
        for (int i = 0; i < totSize; i++) {
            table[i] = NULL;
        }
    }

    ~HashTable() {
        for (int i = 0; i < totSize; i++) {
            if (table[i] != NULL) {
                delete table[i];
            }
        }
        delete[] table;
    }

    void insert(string key, int val) {
        int idx = hashFunction(key);

        // Check for duplicates
        Node* temp = table[idx];
        while (temp != NULL) {
            if (temp->key == key) {
                temp->val = val; // Update value for existing key
                return;
            }
            temp = temp->next;
        }

        Node* newNode = new Node(key, val);
        newNode->next = table[idx]; // Initial will be NULL
        table[idx] = newNode;

        currSize++;

        double lambda = currSize / (double)totSize;
        if (lambda > 1) {
            rehash(); // Worst case O(n)
        }
    }

    bool exists(string key) {
        int idx = hashFunction(key);

        Node* temp = table[idx];
        while (temp != NULL) {
            if (temp->key == key) { // Found
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int search(string key) {
        int idx = hashFunction(key);

        Node* temp = table[idx];
        while (temp != NULL) {
            if (temp->key == key) { // Found
                return temp->val;
            }
            temp = temp->next;
        }
        return -1; // Key not found
    }

    void remove(string key){
        int idx = hashFunction(key);

        Node* temp = table[idx];
        Node* prev = temp;
        while( temp != NULL){ //0(lambda)
            if(temp->key == key){ //erase
                if(prev == temp){ //head
                    table[idx] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    void print() {
        for (int i = 0; i < totSize; i++) {
            cout << "idx" << i << " -> ";
            Node* temp = table[i];
            while (temp != NULL) {
                cout << "(" << temp->key << ", " << temp->val << ") -> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;

    ht.insert("India", 150);
    ht.insert("USA", 50);
    ht.insert("China", 150);
    ht.insert("Nepal", 10);
    ht.insert("UK", 20);

    if (ht.exists("India")) {
        cout << "India Population: " << ht.search("India") << endl;
    }

    if (ht.exists("USA")) {
        cout << "USA Population: " << ht.search("USA") << endl;
    }

    if (!ht.exists("Russia")) {
        cout << "Russia not found in the hash table." << endl;
    }

    ht.print();
    ht.remove("China");
    cout << "-------\n";
    ht.print();
    return 0;
}
