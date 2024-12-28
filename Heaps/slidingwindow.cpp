#include<iostream>
#include<vector>
#include<queue>
#include<deque>
using namespace std;
//using PQ : 0(klogn)
void slidingWindowMax(vector<int> arr, int K){
    priority_queue<pair<int, int>> pq;

    //1st window :
    for(int i=0; i<K; i++){
        pq.push(make_pair(arr[i], i));
    }

    cout << "output : "<< pq.top().first <<  " ";

    for(int i=K; i<arr.size(); i++){
        while(!pq.empty() && pq.top().second <= (i-K)) { //outside window
            pq.pop();
        }
        pq.push(make_pair(arr[i], i));
        cout << pq.top().first << " ";
    }
    cout << endl;
}
//using deque with 0(n)
void slidingwindowmax(vector<int> arr, int K){
    deque<int> dq;
    vector<int> result;

    for(int i=0; i < arr.size(); i++){
        if(!dq.empty() && dq.front() <= i - K){
                dq.pop_front();
        }
        //remove elements outside the window from the front :
        while(!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        //remove elements smaller than the current element from the back :
        dq.push_back(i);
        //add the maximum of the current window to the result (front of deque)
        if( i >= K-1){
            result.push_back(arr[dq.front()]);
        }
    }
}
int main(){
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    int K = 3;

    slidingwindowmax(arr, K);
    // slidingWindowMax(arr, K);
    return 0;
}