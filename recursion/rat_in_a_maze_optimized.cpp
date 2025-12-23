//optimized solution in terms of space complexity
//removing extra visited matrix 

#include <iostream>
#include <vector>
using namespace std;

void helper (vector<vector<int>>& mat, int r, int c, string path, vector<string>& ans){
    //base case
    int n = mat.size();
    if (r<0 || c<0 || r>=n || c>=n || mat[r][c] == 0 || mat[r][c] == -1){
        return;
    }

    if (r == n-1 && c == n-1){//ans
        ans.push_back(path);
        return;
    }
    mat[r][c] = -1;
    //for down
    helper (mat, r+1, c, path+"D", ans);
    //up
    helper (mat, r-1, c, path+"U", ans);
    //right
    helper (mat, r, c+1, path+"R", ans);
    //Left
    helper (mat, r, c-1, path+"L", ans);

    //backtracking
    mat[r][c] = 1;
}

vector<string> findpath(vector<vector<int>>& mat){
    int n = mat.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<string> ans;
    string path = "";

    helper (mat, 0, 0, path, ans);

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