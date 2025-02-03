#include <iostream>
#include <list>
#include<stack>
#include <vector>
using namespace std;

class Graph {
    int V;
    list<int>* adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }    

    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    bool isCycle(int src, vector<bool> &vis, vector<bool> &rec){
        vis[src] = true;
        rec[src] = true;

        for(int v : adj[src]){
            if(!vis[v]) {
                if(isCycle(v,vis,rec)) {
                    return true;
                }
            } else if (rec[v]) {
                return true;
            }
        }

        rec[src] = false;
        return false;
    }

    void topoSort(int src, vector<bool>& vis, stack<int> &s){
        vis[src] = true;
        for(int v : adj[src]) {
            if(!vis[v]){
                topoSort(v,vis, s);
            }
        }
        s.push(src);
    }

    vector<int>findorder(){
        vector<bool> vis(V, false);
        vector<bool> rec(V, false);
        vector<int> ans;

        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(isCycle(i,vis,rec)) {
                    return ans;
                }
            }
        }
        //topological sorting
        vector<bool> vis2(V, false);
        stack<int> s;
        for(int i=0; i<V; i++){
            if(!vis2[i]) {
                topoSort(i,vis2, s);
            }
        }
        while(s.size()> 0){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }   
};

int main(){
    Graph graph(4);
    graph.addEdge(1,0);
    graph.addEdge(2,0);
    graph.addEdge(3,1);
    graph.addEdge(3,2);

    vector<int> results = graph.findorder();

    if(results.empty()) {
        cout << "Cycle detected! no valid course order . \n";
    } else {
        cout << "Valid course order: ";
        for(int course : results){
            cout << course << " ";
        }
        cout << endl;
    }
    return 0;
}