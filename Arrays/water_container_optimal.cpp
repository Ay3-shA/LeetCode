//container with most water 
#include<iostream>
#include<vector>
using namespace std;

int main (){
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = height.size();
    int maxWater = 0;
    //left pointer - right pointer 
    int lp=0, rp=n-1;
    while(lp<rp){
        int w = rp-lp;
        int ht = min(height[lp], height[rp]);
        int currWater = w * ht;
        maxWater=max(maxWater, currWater);

        height[lp]<height[rp] ? lp++ : rp--;
    }
    cout<<maxWater;


    return 0;
}