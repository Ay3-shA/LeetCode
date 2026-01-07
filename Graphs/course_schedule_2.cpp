#include<iostream>
#include<vector>
#include<list>
#include<stack>
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
                }else if(recPath[v]){ //backedge -> cycle
                    return true;
                }
            }
        }

        recPath[src] = false;
        return false;

    }

    void topoOrder(int src, vector<bool>& vis, stack<int>& s, vector<vector<int>>& edges){
        vis[src]=true;

        for(int i=0; i<edges.size(); i++){
            int v = edges[i][0];
            int u = edges[i][1];

            if (u == src){
                if (!vis[v]){
                    topoOrder(v, vis, s, edges);
                }
            }
        }

        s.push(src);

    }

    vector<int> findOrder(int n, vector<vector<int>>& edges){
        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(isCycleDFS(i, vis, recPath, edges)){
                    return ans;
                }
            }
        }
        //topological sorted function

        stack<int> s;
        vis.assign(n, false);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                topoOrder(i, vis, s, edges);
            }
        }

        while(s.size()>0){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;

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

    vector<int> order = g.findOrder(n, edges);

    for(int x : order){
        cout << x << " ";
    }


    return 0;
}