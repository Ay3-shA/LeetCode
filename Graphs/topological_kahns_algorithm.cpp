#include<iostream>
#include<vector>
#include<queue>
#include<list>
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
    
    void topoSort(){
        vector<int> result;
        //calculate indegree
        vector<int> indegree(V, 0);
        for(int u=0;u<V;u++){
            for(int v : l[u]){
                indegree[v]++;
            }
        }
        //0 indegree => Q
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        //bfs
        while(q.size()>0){
            int curr = q.front();
            q.pop();
            result.push_back(curr);

            for(int v : l[curr]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }

        }

        //result
        for(int val : result){
            cout<<val<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Graph g(6);
    g.addEdge(3, 1);
    g.addEdge(2, 3);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(5, 0);
    g.addEdge(5, 2);
    
    g.topoSort();

    return 0;
}