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
    }

    bool isCycleDFS(int src, vector<bool>& vis, vector<bool>& recPath, vector<vector<int>>& edges){
        vis[src] = true;
        recPath[src] = true;

        for(int i=0; i<edges.size(); i++){
            int v = edges[i][0];
            int u = edges[i][1];

            if (u == src){
                if (!vis[v]){
                    if(isCycleDFS(v, vis, recPath, edges)){
                        return true;
                    }
                }else if(recPath[v]){
                    return true;
                }
            }
        }

        recPath[src] = false;
        return false;

    }

    bool canFinish(int n, vector<vector<int>>& edges){
        vector<bool> vis (V, false);
        vector<bool> recPath(V, false);

        for (int i=0; i<n; i++){
            if(!vis[i]){
                if(isCycleDFS(i, vis, recPath, edges)){
                    return false;
                }
            }
        }

        return true;

    }
};

int main() {
    int n = 5;
    // edges: {v, u} means u -> v
    vector<vector<int>> edges = {
        {1, 0},
        {2, 0},
        {2, 1},
        {3, 1},
        {4, 2}
    };

    Graph g(n);

    bool result = g.canFinish(n, edges);

    if (result)
        cout << "No cycle detected. Can finish.\n";
    else
        cout << "Cycle detected. Cannot finish.\n";
    return 0;
}