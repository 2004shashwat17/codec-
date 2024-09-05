//In-Build sort function ?
#include<iostream>
#include<algorithm>
using namespace std;

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) { // Start loop from 0
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[8] = {1,4,1,3,2,4,3,7};
    sort(arr,arr+8); // Sort in Ascending Order
    sort(arr,arr+8, greater<int>()); //Sort in Descending Order
    print(arr,8);
    return 0;
}