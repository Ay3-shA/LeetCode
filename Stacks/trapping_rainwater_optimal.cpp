#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

class solution{
    public:

    int trapWater(vector<int>& height){

        int n = height.size();
        int ans = 0;
        int l=0, r=n-1;
        int lmax = 0, rmax = 0;

        while(l<r){
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            
            if(lmax < rmax){
                ans += lmax - height[l];
                l++;
            }
            else{
                ans += rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};

int main (){

    solution s;

    vector<int>height = {4, 2, 0, 3, 2, 5};
    cout<< s.trapWater(height);

    return 0;
}