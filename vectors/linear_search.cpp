#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> nums = {2, 4, 8, 2, 1 ,7};
    int n=nums.size();
    int target = 2;

    for (int i=0; i<n; i++){
        if(nums[i] == target){
            cout<<i<<" ";
        }
    }

    return 0;
}