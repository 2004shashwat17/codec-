#include<iostream>
#include <vector>
using namespace std;

void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << endl;
    }
    cout << endl;
}
int partition(int arr[], int si, int ei){
    int i = si-1;
    int pivot = arr[ei];

    for(int j=si; j<ei; j++){
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
        //pivotIdx = i    
        // Move pivot to its correct position
    swap(arr[i + 1], arr[ei]);
    return i + 1;
}
void quicksort(int arr[], int si, int ei){//0(n * logn)
    if(si >= ei) {
        return;
    }   
    int pivotidx = partition(arr, si, ei);
    quicksort(arr, si, pivotidx-1); //left half
    quicksort(arr, pivotidx+1 , ei); //right half
}

int main(){
    int arr[6] = {6,3,7,5,2,4};
    int n = 6;
    quicksort(arr, 0, n-1);
    printArr(arr,n);   
    return 0;
}