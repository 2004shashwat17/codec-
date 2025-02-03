#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph {
    int V;
    list<int>* l;
public :
    Graph(int V){
        this->V = V;
        l= new list<int>[V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }    

    bool pathHelper(int src, int dest, vector<bool> &vis){
        if(src == dest){
            return true;
        }
        vis[src] = true;
        list<int> neighbours = l[src];

        for(int v : neighbours){
            if(!vis[v]){
                if(pathHelper(v, dest, vis)) {
                    return true;
                }
            }
        }
        return false;
    }    

    bool hasPath(int src, int dest){
        vector<bool> vis(V, false);
        return pathHelper(src, dest, vis);
    }
};

int main(){
    Graph graph(7);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

   cout << graph.hasPath(0,5) << endl;
   return 0;
   
}