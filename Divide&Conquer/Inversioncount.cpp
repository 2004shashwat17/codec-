#include <iostream>
using namespace std;

// Function to merge two sorted subarrays and count inversions
int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;    // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left;    // Starting index to be sorted
    int inv_count = 0; // Initialize inversion count

    // Merge the two subarrays
    while ((i <= mid) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            // No inversion if arr[i] <= arr[j]
            temp[k++] = arr[i++];
        } else {
            // Inversion will occur, because arr[i] > arr[j]
            temp[k++] = arr[j++];
            inv_count += (mid + 1) - i;  // Number of inversions
        }
    }

    // Copy the remaining elements of the left subarray (if any)
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements of the right subarray (if any)
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the sorted subarray into the original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;  // Return the inversion count
}

// Function to divide the array and count inversions recursively
int mergeSortAndCount(int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;
    if (left < right) {
        mid = (left + right) / 2;

        // Count inversions in the left subarray
        inv_count += mergeSortAndCount(arr, temp, left, mid);

        // Count inversions in the right subarray
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);

        // Count inversions while merging the two subarrays
        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

// Function to count inversions in the array
int countInversions(int arr[], int n) {
    int temp[n];
    return mergeSortAndCount(arr, temp, 0, n - 1);
}

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int inversionCount = countInversions(arr, n);
    cout << "Inversion Count: " << inversionCount << endl;

    return 0;
}
