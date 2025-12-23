#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<vector<int>> s;

void getAllComibination(vector<int>& arr, int idx, int target, vector<vector<int>>& ans, vector<int>& combin){

    //base case
    if(idx==arr.size() || target<0){
        return;
    }
    if(target == 0){
        if(s.find(combin) == s.end()){
            ans.push_back(combin);
            s.insert(combin);
        }
        return;
    }

    combin.push_back(arr[idx]);
    //single choice 
    getAllComibination(arr, idx+1, target-arr[idx], ans, combin);
    //multiple
    getAllComibination(arr, idx, target-arr[idx], ans, combin);
    combin.pop_back();
    //exclusion
    getAllComibination(arr, idx+1, target, ans, combin);

    return;
}

vector<vector<int>> combinationSum (vector<int>& arr, int target){
    vector<vector<int>> ans;
    vector<int> combin;

    getAllComibination(arr, 0, target, ans, combin);

    return ans;

}

int main(){

    vector<int> arr = {2, 3, 5};
    int target = 8;

     vector<vector<int>> result = combinationSum(arr, target);

    // print result
    for (auto comb : result) {
        cout << "[ ";
        for (int x : comb) cout << x << " ";
        cout << "]\n";
    }


    return 0;
}