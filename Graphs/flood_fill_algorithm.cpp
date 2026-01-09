#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class solution{
    public:
    void dfs(vector<vector<int>>& image, int i, int j, int newColor, int orgColor){

        if(i<0||j<0||i>=image.size()||j>=image[0].size()||image[i][j]!=orgColor||image[i][j]==newColor){
            return;
        }

        image[i][j]=newColor;

        dfs(image, i-1, j, newColor, orgColor); //top
        dfs(image, i, j+1, newColor, orgColor); //right
        dfs(image, i+1, j, newColor, orgColor); //bottom
        dfs(image, i, j-1, newColor, orgColor); //left

    }
};

int main (){

    solution s;
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    int orgColor = image[1][1];
    s.dfs(image, 1, 1, 2, orgColor);

    for (int i = 0; i < image.size(); i++) {
    for (int j = 0; j < image[i].size(); j++) {
        cout << image[i][j] << " ";
    }
    cout << endl;
}
    return 0;
}