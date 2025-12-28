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

    //cycle detection

    bool isCycleDirDFS(int src, vector<bool>& vis, vector<bool> &recPath){//dfs algo
        vis[src] = true;
        recPath[src] = true;

        for (int v : l[src]){
            if(!vis[v]){
                if(isCycleDirDFS(v, vis, recPath)){
                    return true;
                }
            }else if(recPath[v]){
                return true;
            }

        }
        recPath[src] = false;
        return false;
    }

    bool isCycle(){
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for (int i=0;i<V;i++){
            if(!vis[i]){
                if(isCycleDirDFS(i, vis, recPath)){
                    return true;
                }
            }
        }
        return false;
    }
    
};

int main(){
    Graph g(4);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);

    cout<< g.isCycle()<<endl;

    return 0;
}