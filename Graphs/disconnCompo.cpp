#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph {
    int V;
    list<int>* l;
public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V]; 
    }    

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    //using BFS
    void bfsHelper(int st, vector<bool> &vis){
        queue<int> q;
        q.push(st);
        vis[st] = true;

        while(q.size() > 0){
            int curr = q.front();
            q.pop();

            cout << curr << " ";

            list<int> neighbours = l[curr];
            for(int neigh : neighbours){
                if(!vis[neigh]){
                    vis[neigh] = true;
                    q.push(neigh);
                }
            }
        }
        cout << endl;
    }

    void bfs() {
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                bfsHelper(i, vis);
                cout << endl;
            }
        }
    }
    //using DFS
    void dfsHelper(int u, vector<bool> &vis){
        cout << u << " ";
        vis[u] = true;
        list<int> neighbours = l[u];

        for(int v : neighbours) {
            if(!vis[v]){
                dfsHelper(v,vis);
            }
        }
    }
    void dfs() {
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++){
            if(!vis[i]) {
                dfsHelper(i, vis);
                cout << endl;
            }
        }

        cout << endl;
    }
};
int main() {
    Graph graph(10); // Adjusted the size of the graph to include 0-9 nodes

    // Adding edges for the first connected component
    graph.addEdge(1, 6);
    graph.addEdge(6, 4);
    graph.addEdge(4, 3);
    graph.addEdge(4, 9);
    graph.addEdge(3, 8);
    graph.addEdge(3, 7);

    // Adding edges for the second connected component
    graph.addEdge(2, 5);
    graph.addEdge(2, 0);

    // Perform DFS to traverse all connected components
    cout << "DFS Traversal of the Graph:" << endl;
    graph.dfs();

    return 0;
}
