#include <iostream>
#include <vector>
using namespace std;

void helper (vector<vector<int>>& mat, int r, int c, string path, vector<string>& ans, vector<vector<bool>>& visited){
    //base case
    int n = mat.size();
    if (r<0 || c<0 || r>=n || c>=n || mat[r][c] == 0 || visited[r][c] == true){
        return;
    }

    if (r == n-1 && c == n-1){//ans
        ans.push_back(path);
        return;
    }
    visited[r][c] = true;
    //for down
    helper (mat, r+1, c, path+"D", ans, visited);
    //up
    helper (mat, r-1, c, path+"U", ans, visited);
    //right
    helper (mat, r, c+1, path+"R", ans, visited);
    //Left
    helper (mat, r, c-1, path+"L", ans, visited);

    //backtracking
    visited[r][c] = false;
}

vector<string> findpath(vector<vector<int>>& mat){
    int n = mat.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<string> ans;
    string path = "";

    helper (mat, 0, 0, path, ans, visited);

    return ans;

}


int main (){

    vector<vector<int>> mat = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};

    vector<string> ans = findpath(mat);
    for(string path : ans){
        cout<<path<<endl;
    }

    return 0;
}