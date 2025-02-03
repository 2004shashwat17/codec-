#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <cmath>
using namespace std;

class Graph {
    int V;
    list<pair<int, int>>* adj;
    bool isUndir;

public:
    Graph(int V, bool isUndir = true) {
        this->V = V;
        adj = new list<pair<int, int>>[V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v, int wt) {
        adj[u].push_back(make_pair(v, wt));
        if (isUndir)
            adj[v].push_back(make_pair(u, wt));
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<bool> inMST(V, false);
        pq.push({0, 0});
        int minCost = 0;
        int edgesUsed = 0;

        while (!pq.empty() && edgesUsed < V) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (inMST[u]) continue;
            
            inMST[u] = true;
            minCost += cost;
            edgesUsed++;

            for (int v = 0; v < V; v++) {
                if (!inMST[v]) {
                    int wt = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    pq.push({wt, v});
                }
            }
        }
        return minCost;
    }
};

int main() {
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 10}};

    Graph graph(points.size(), false);
    cout << "Minimum Cost to Connect Points: " << graph.minCostConnectPoints(points) << endl;
    
    return 0;
}
