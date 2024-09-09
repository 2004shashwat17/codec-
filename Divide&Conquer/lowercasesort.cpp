#include <iostream>
#include <vector>
#include <string>

using namespace std;

void merge(string arr[], int lo, int mid, int hi) {
    vector<string> temp;
    int i = lo;
    int j = mid+1;

    // Merge elements from both halves
    while( i <= mid && j<= hi) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy any remaining elements from the first half
    while ( i<= mid){
        temp.push_back(arr[i]);
        i++;
    }
    //Copy any remaining elements from the second half
    while(j<= hi){
        temp.push_back(arr[j]);
        j++;
    }
    //copy the merged result back into the original array.
    for (int idx = 0, x = lo; x <= hi; x++) {
        arr[x] = temp[idx++];
    }
}
//Merge Sort function to recursively sort the array
void mergeSort(string arr[], int lo, int hi) {
    if(lo <= hi) return;
    int mid = lo + (hi - lo)/2;

    //Recursively divide the
    mergeSort(arr, lo, mid);
    mergeSort(arr, mid+1, hi);

    //merge the two sorted halves
    merge(arr, lo, mid, hi);
}
int main(){
    string arr[4] = {"sun", "earth", "mars", "mercury"}; //Input array
    int n = 4; //Size of the array

    //Apply merge sort to sort the array
    mergeSort(arr,0,n-1);

    //Print the sorted array
    for(int i=0; i<n; i++){
        cout << arr[i] << endl;
    }
    
    return 0;
}