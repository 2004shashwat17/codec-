//Insertion Sort ?
#include<iostream>
using namespace std;
void print(int arr[], int n){
  for(int i=0; i<n ; i++ ){
    cout << arr[i] << " ";
  }
  cout << endl;
}
void insertionsort (int *arr,int n ) { 
  for(int i=1; i<n; i++){
    int curr = arr[i];
    int prev = i-1;
    while(prev >= 0 && arr[prev] > curr){
      swap(arr[prev], arr[prev+1]);
      prev--;
    }
    arr[prev+1] = curr;
  }
  print(arr,n);
}
int main(){
  int arr[5]= {5,4,3,2,1};
  insertionsort(arr , 5);
  return 0;
}
// Sort the array in descending order using insertion sort -> char ch[]= {'f','b','a','e','c','d'} ?
#include<iostream>
using namespace std;

void print(char arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " , ";
    }
    cout << endl;
}

void insertionsort(char *arr, int n) { 
    for(int i = 1; i < n; i++) {
        char curr = arr[i];
        int prev = i - 1;
        while(prev >= 0 && arr[prev] < curr) {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
    print(arr, n);
}

int main() {
    char ch[6] = {'f', 'b', 'a', 'e', 'c', 'd'};
    insertionsort(ch, 6);
    return 0;
}