#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <vector>
using namespace std;

class Graph {
    int V;
    list<pair<int,int>> * l; // Adjacency List: (neighbor, weight)
    bool isUndir;

public:
    Graph(int V, bool isUndir = true) {
        this->V = V;
        l = new list<pair<int, int>>[V];
        this->isUndir = isUndir;
    }     

    void addEdge(int u, int v, int wt) { 
        l[u].push_back(make_pair(v, wt));
        if(isUndir)
            l[v].push_back(make_pair(u, wt));
    }

    void primsAlgo(int src) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // Min-Heap (wt, (u, v))

        vector<bool> mst(V, false);
        vector<int> parent(V, -1);  // To store MST edges
        pq.push({0, {src, -1}});  // (wt, (current node, parent node))
        int ans = 0; 

        cout << "Edges in MST:\n";
        
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int wt = top.first;
            int u = top.second.first;
            int par = top.second.second;

            if (!mst[u]) {
                mst[u] = true;
                ans += wt;

                // Print the MST Edge
                if (par != -1) 
                    cout << par << " - " << u << " (Weight: " << wt << ")\n";

                for (auto n : l[u]) {
                    int v = n.first;
                    int currwt = n.second;
                    if (!mst[v]) {
                        pq.push({currwt, {v, u}});
                    }
                }
            }
        }
        cout << "Final cost of MST = " << ans << endl;
    }
};

int main() {
    Graph graph(4);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    graph.addEdge(1, 3, 40);
    graph.addEdge(2, 3, 50);

    graph.primsAlgo(0);
    return 0;
}