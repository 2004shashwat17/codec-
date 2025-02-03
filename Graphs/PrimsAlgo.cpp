#include<iostream>
#include<stack>
#include<queue>
#include<list>
#include<vector>
using namespace std;

class Graph {
    int V;
    list<pair<int,int>> * l; //int, int: neighbour + wt
    bool isUndir;

public:
    Graph(int V, bool isUndir = true){
        this->V = V;
        l = new list<pair<int, int>>[V];
        this->isUndir = isUndir;
    }     

    void addEdge(int u, int v, int wt) { //u---v (weighted)
        l[u].push_back(make_pair(v,wt));
        if(isUndir)
            l[v].push_back(make_pair(u,wt));
    }

    void primsAlgo(int src){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //min-heap

        vector<bool> mst(V,false);
        pq.push(make_pair(0, src));
        int ans = 0; 

        while(pq.size() > 0) {
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if(!mst[u]){
                mst[u] = true;
                ans += wt;
                list<pair<int, int>> neighbors = l[u];
                for(pair<int,int> n : neighbors) {
                    int v = n.first;
                    int currwt = n.second;
                    pq.push(make_pair(currwt, v));
                }
            }
        }
        cout << "final cost of MST = " << ans << endl;
    }
};

int main(){
    Graph graph(4);

    graph.addEdge(0,1,10);
    graph.addEdge(0,2, 15);
    graph.addEdge(0,3, 30);

    graph.addEdge(1,3,40);

    graph.addEdge(2,3,50);

    graph.primsAlgo(0);
    return 0;
}