#include<iostream>
using namespace std;

int binsearch(int arr[], int si, int end, int key){
    if(si > end){
        return -1;
    }
    int mid = si + (end - si) / 2;
    if(arr[mid] == key){
        return mid;
    } else if(arr[mid] > key){
        return binsearch(arr, si, mid-1, key);
    } else {
        return binsearch(arr, mid+1, end, key);
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7}; // example sorted array
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5; // example key to search for

    int result = binsearch(arr, 0, n-1, key);

    if(result != -1){
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}
