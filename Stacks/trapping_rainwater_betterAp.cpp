#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

class solution{
    public:

    int trapWater(vector<int>& height){

        int n = height.size();
        vector<int> lmax(n, 0);
        vector<int> rmax(n, 0);

        lmax[0]=height[0];
        rmax[n-1]=height[n-1];

        //finding left maximum
        for (int i=1;i<n;i++){
            lmax[i] = max(lmax[i-1], height[i]);
        }

        //finding right maximum
        for(int i=n-2; i>=0; i--){
            rmax[i] = max(rmax[i+1], height[i]);
        }

        //calculating ans
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += min(lmax[i], rmax[i]) - height[i];
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