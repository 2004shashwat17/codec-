#include<iostream>
using namespace std;

void occurence(int arr[], int key, int i, int n) {
    if(i == n) {
        return;
    }
    if(arr[i] == key) {
        cout << i << " ";
    }
    occurence(arr, key, i+1, n);
}

int main() {
    int arr[] = {3, 2, 4, 5, 6, 2, 7, 2, 2}; // Missing semicolon added
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 2;

    cout << "The key " << key << " is found at indices: ";
    occurence(arr, key, 0, n); // Correct function call

    return 0;
}
