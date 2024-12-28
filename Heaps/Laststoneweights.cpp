#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int lastStoneWeight (vector<int> &stones){
    priority_queue<int> maxHeap (stones.begin(), stones.end());
    while(maxHeap.size() > 1){
        int stone1 = maxHeap.top();
        maxHeap.pop();
        int stone2 = maxHeap.top();
        maxHeap.pop();
        if(stone1 != stone2){
            maxHeap.push(stone1 - stone2);
        }
    }
    return maxHeap.empty() ? 0 : maxHeap.top();
};
int main(){
    vector<int> stones = {2,7,4,1,8,1};
    int result = lastStoneWeight(stones);
    cout <<"Last Stone Weight : " <<result << endl;
    return 0;
}