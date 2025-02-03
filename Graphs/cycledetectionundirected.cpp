#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<string>    
using namespace std;

class Graph {
    int V;               // Number of vertices
    list<int>* l;        // Adjacency list

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    ~Graph() {
        delete[] l;      // Free dynamically allocated memory
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print() {
        for (int u = 0; u < V; u++) {
            cout << u << " : ";
            for (int v : l[u]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }


    bool undirCycleHelper(int src, int par, vector<bool> &vis){ //0(V+E)
        vis[src] = true;
        list<int> neighbors = l[src];

        for(int v : neighbors) {
            if(!vis[v]){
                if(undirCycleHelper(v,src,vis)) {
                    return true;
                }
            } else {
                if(v != par){ //cycle condn
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycleUndir(){
        vector<bool> vis(V, false);
        return undirCycleHelper(0, -1, vis);
    }

};

int main(){
    int V=5;
    Graph graph(V);

    //undirected graph
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(0,3);
    graph.addEdge(1,2);
    graph.addEdge(3,4);

    cout << graph.isCycleUndir() << endl; //1

    return 0;
}