//Counting Sort ?
#include <iostream>
#include <climits>
using namespace std;

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) { // Start loop from 0
        cout << arr[i] << " ";
    }
    cout << endl;
}

void countingsort(int arr[], int n) {
    int freq[10000] = {0}; // range
    int minval = INT_MAX, maxval = INT_MIN;

    // 1st step - O(n)
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
        minval = min(minval, arr[i]);
        maxval = max(maxval, arr[i]);
    }

    // 2nd step - O(max - min)
    for (int i = minval, j = 0; i <= maxval; i++) {
        while (freq[i] > 0) {
            arr[j++] = i;
            freq[i]--;
        }
    }

    print(arr, n);
}

int main() {
    int arr[8] = {1, 4, 1, 3, 2, 4, 3, 7};
    countingsort(arr, 8);
    return 0;
}