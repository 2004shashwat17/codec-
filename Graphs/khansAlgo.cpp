#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int>* l;
    
public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }    

    void addEdge(int u, int v){
        l[u].push_back(v);
    }

    void calcDegree(vector<int> &indeg){
        for(int u=0; u<V; u++){
            list<int> neighbors = l[u];
            for(int v : neighbors){
                indeg[v]++;
            }
        }
    }

    void topoSort2() {
        vector<int> indeg(V, 0);
        calcDegree(indeg);
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        while(q.size() > 0){
            int curr = q.front();
            q.pop();
            cout << curr << " ";
            list<int> neighbors = l[curr];
            for(int v : neighbors){
                indeg[v]--;
                if(indeg[v] == 0){
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
};
int main(){
    Graph graph(6);
    graph.addEdge(2,3);
    graph.addEdge(3,1);

    graph.addEdge(4,0);
    graph.addEdge(4,1);

    graph.addEdge(5,0);
    graph.addEdge(5,2);

    graph.topoSort2();

    return 0;
}