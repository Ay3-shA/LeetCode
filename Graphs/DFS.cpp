#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    //dynamic array
    list<int> *l; //int *arr
    public:
    //constructor
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
        //arr = new int[V]
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    //DFS - Depth First Search
    void dfsHelper(int u, vector<bool>& vis){
        cout<<u<<" ";
        vis[u] = true;

        for(int v : l[u]){
            if (!vis[v]){
                dfsHelper(v, vis);
            }
        }
    }
    //connected graph
    void dfs(){
        int src = 0;
        vector<bool> vis(V, false);

        dfsHelper(src, vis);
        cout<<endl;
    }
    
};

int main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.dfs();

    return 0;
}