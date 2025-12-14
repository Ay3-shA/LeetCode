#include <iostream>
#include <vector>
using namespace std;

void getPerms(vector<int>& nums, int idx,vector<vector<int>>& ans ){
    int n = nums.size();
    //base case 
    if(idx==n){
        //ans.push_back(nums);
        for (int val : nums) cout << val << " ";
        cout << endl;
        return;
    }
    //include
    for(int i=idx; i<n; i++){
        swap(nums[idx], nums[i]);
        getPerms(nums, idx+1, ans);

        swap(nums[idx], nums[i]);//backtracting
    }
}

vector<vector<int>> permute (vector<int>& nums){
    vector<vector<int>> ans;
    getPerms(nums, 0, ans);
    return ans;
}

int main (){
    vector<int> nums = {1, 2, 3};
    permute(nums);
    return 0;
}

