#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

class Graph {
    int V;
    list<pair<int, int>>* l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int wt) {
        l[u].push_back(make_pair(v, wt));
    }
};

class Info { 
public:
    int u;
    int cost;
    int stops;

    Info(int u, int cost, int stops) {
        this->u = u;
        this->cost = cost;
        this->stops = stops;
    }
};

int findCheapestFlight(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    queue<Info> q;
    vector<int> distance(n, INT_MAX);  

    distance[src] = 0;
    q.push(Info(src, 0, -1));

    while (!q.empty()) {
        Info curr = q.front();
        q.pop();

        for (int i = 0; i < flights.size(); i++) {
            if (flights[i][0] == curr.u) { 
                int v = flights[i][1];
                int wt = flights[i][2];

                if (distance[v] > curr.cost + wt && curr.stops + 1 <= k) {
                    distance[v] = curr.cost + wt;
                    q.push(Info(v, distance[v], curr.stops + 1));
                }
            }
        }
    }
    return (distance[dst] == INT_MAX) ? -1 : distance[dst];  
}

int main() {
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600},
        {2, 3, 200}
    };

    int n = 4, src = 0, dst = 3, k = 1;
    
    Graph graph(n);  

    cout << "Cheapest Flight Cost: " << findCheapestFlight(n, flights, src, dst, k) << endl;
    return 0;
}
