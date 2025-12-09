//container with most water 
#include<iostream>
#include<vector>
using namespace std;

int main (){
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = height.size();
    int maxWater = 0;

    for (int i=0; i<n;i++){
        for (int j=i+1; j<n; j++){
            int w = j-i;
            int ht = min(height[i], height[j]);
            int area = w * ht;
            maxWater= max(maxWater, area);
        }
    }
    cout<<maxWater;
    return 0;
}