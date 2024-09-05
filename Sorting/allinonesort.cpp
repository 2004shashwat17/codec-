//use all sorting algorithm to sort an array in descending order for an array -> [3,6,2,1,8,7,4,5,3,1]?
#include<iostream>
#include<climits>
using namespace std;

void print(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int *arr, int n) {
    for(int i = 0; i < n - 1; i++) {
        bool isSwap = false; // optimized
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] < arr[j + 1]) { // Changed > to <
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if(!isSwap) {
            return;
        }
    }
    print(arr, n);
}

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int maxIndex = i; // Changed variable name
        for(int j = i + 1; j < n; j++) {
            if(arr[j] > arr[maxIndex]) { // Changed < to >
                maxIndex = j;
            }
        }
        swap(arr[i], arr[maxIndex]);
    }
    print(arr, n);
}

void countingSort(int arr[], int n) {
    int freq[10000] = {0}; // range
    int minval = INT_MAX, maxval = INT_MIN;

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
        minval = min(minval, arr[i]);
        maxval = max(maxval, arr[i]);
    }

    for (int i = maxval, j = 0; i >= minval; i--) { // Changed loop direction
        while (freq[i] > 0) {
            arr[j++] = i;
            freq[i]--;
        }
    }
    print(arr, n);
}

void insertionSort(int *arr, int n) {
    for(int i = 1; i < n; i++) {
        int curr = arr[i];
        int prev = i - 1;
        while(prev >= 0 && arr[prev] < curr) { // Changed > to <
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
    print(arr, n);
}

int main() {
    int arr[10] = {3,6,2,1,8,7,4,5,3,1};
    insertionSort(arr, 10);
    countingSort(arr, 10);
    selectionSort(arr, 10);
    bubbleSort(arr, 10);
    return 0;
}