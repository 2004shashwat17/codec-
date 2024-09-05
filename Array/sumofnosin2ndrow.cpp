//Q2) Print out the sum of the numbers in the second row of the “nums” array ?
#include<iostream>
using namespace std;
void sumofsecondrow(int nums[][3], int n, int m){
  int sum = 0;
  for(int j=0 ; j<m ; j++){
    sum +=nums[1][j];
  }
  cout << "sum is :" << sum << endl;
}
int main(){
  int nums[3][3] = {{1,4,9},{11,4,3},{2,2,3}};
  sumofsecondrow(nums, 3, 3);
  return 0;
}