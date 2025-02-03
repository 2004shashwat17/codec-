#include<iostream>
#include<vector>
#include<list>

using namespace std;

class Graph {
    int V;
    list<int> *adj; 

public:
    Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    }

    ~Graph() {
        delete[] adj;
    }

    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void pathHelper(int src, int dest, vector<bool>& vis, string path){ //0(V+E)
        if(src == dest){
            cout << path << dest << endl;
            return; 
        }

        vis[src] = true;
        // path.push_back(src);
        path += to_string(src); 

        list<int>neighbors = adj[src];

        for(int v : neighbors){
            if(!vis[v]) {
                pathHelper(v, dest, vis, path);
            }
        }

        path = path.substr(0, path.size()-1);
        vis[src] = false;
    }

    void printallpaths(int src, int dest){
        vector<bool> vis(V, false);
        string path = "";
        pathHelper(src, dest, vis, path);
    }

};

int main(){

    Graph graph(6);
    graph.addEdge(0,3);
    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.addEdge(4,0);
    graph.addEdge(4,1);
    graph.addEdge(5,0);
    graph.addEdge(5,2);

    graph.printallpaths(5,1);
    return 0;
}