#include <iostream>
#include <vector>
using namespace std;

bool isValidHelper(vector<vector<int>>& grid, int row, int col, int n, int expVal){
    //base case
    if (row<0 || col<0 || row>=n || col>=n || grid[row][col] != expVal){
        return false;
    }

    if (expVal==n*n-1){
        return true;
    }

    //8 possible moves
    int ans1 = isValidHelper(grid, row-2, col+1, n, expVal+1);
    int ans2 = isValidHelper(grid, row-1, col+2, n, expVal+1);
    int ans3 = isValidHelper(grid, row+1, col+2, n, expVal+1);
    int ans4 = isValidHelper(grid, row+2, col+1, n, expVal+1);
    int ans5 = isValidHelper(grid, row+2, col-1, n, expVal+1);
    int ans6 = isValidHelper(grid, row+1, col-2, n, expVal+1);
    int ans7 = isValidHelper(grid, row-1, col-2, n, expVal+1);
    int ans8 = isValidHelper(grid, row-2, col-1, n, expVal+1);

    return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8; 
}

bool checkValidGrid(vector<vector<int>>& grid){
    return isValidHelper(grid, 0, 0, grid.size(), 0);
}

int main(){

    vector<vector<int>> grid = {
        {0,3,6},
        {5,8,1},
        {2,7,4}
        // {0, 59, 38, 33, 30, 17, 8, 63},
        // {37, 34, 31, 60, 9, 62, 29, 16},
        // {58, 1, 36, 39, 32, 27, 18, 7},
        // {35, 48, 41, 26, 61, 10, 15, 28},
        // {42, 57, 2, 49, 40, 23, 6, 19},
        // {47, 50, 45, 54, 25, 20, 11, 14},
        // {56, 43, 52, 3, 22, 13, 24, 5},
        // {51, 46, 55, 44, 53, 4, 21, 12}
    };
    cout << checkValidGrid(grid)<<endl;
    if(checkValidGrid(grid))
        cout << "Valid Knight Tour";
    else
        cout << "Invalid Knight Tour";
    return 0;
}