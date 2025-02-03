#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

class Graph {
    int V;
    list <pair<int,int>> * l;
public:
    Graph(int V){
        this->V = V;
        l = new list<pair<int, int>>[V];
    }   

    void addEdge(int u, int v, int weight){
        l[u].push_back({v, weight});
        l[v].push_back({u, weight});
    } 

    void print() {
        for(int u=0; u<V; u++){
            // list<int> neigbours = l[u];
            cout << u << " : ";
            for(auto neigbours : l[u]) {
                cout << "("<< neigbours.first << " , "<< neigbours.second << " )";
            }
            cout << endl;
        }
    }
};

int main(){
    Graph graph(5);

    graph.addEdge(0,1,10);
    graph.addEdge(1,2,20);
    graph.addEdge(1,3,30);
    graph.addEdge(2,3,40);
    graph.addEdge(2,4,50);

    graph.print();
    return 0;
}