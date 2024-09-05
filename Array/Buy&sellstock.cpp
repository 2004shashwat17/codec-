//Buy & sell stocks ?
#include<iostream>
#include<climits>
using namespace std;
void maxProfit(int *prices, int n){
  int bestbuy[10];
  bestbuy[0] = INT_MAX;
  for(int i=1; i<n; i++){
    bestbuy[i] = min(bestbuy[i-1], prices[i-1]);
  }

  int maxProfit = 0;
  for(int i=0 ; i<n ; i++){
    int currProfit = prices[i] - bestbuy[i];
    maxProfit = max(maxProfit , currProfit);
  }
  cout << "max Profit = "<< maxProfit << endl;
}
int main(){
  int prices[6]= {7,1,5,3,6,4};
  int n = sizeof(prices)/sizeof(int);

  maxProfit(prices, n);
  return 0;
}