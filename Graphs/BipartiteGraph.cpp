#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

class Graph {
    int V;
    list<int> *l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    ~Graph() {
        delete[] l;
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool isBipartite() {
        vector<int> color(V, -1); // -1 means uncolored
        vector<bool> vis(V, false);
        
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) { // Check all components
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();

                    for (int v : l[curr]) {
                        if (color[v] == -1) {
                            color[v] = !color[curr]; // Assign opposite color
                            q.push(v);
                        } else if (color[v] == color[curr]) {
                            return false; // Graph is not bipartite
                        }
                    }
                }
            }
        }
        return true; // If all components are checked, it's bipartite
    }
};

int main() {
    Graph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);

    cout << (graph.isBipartite() ? "Yes, the graph is Bipartite" : "No, the graph is not Bipartite") << endl;
    
    return 0;
}
