#include <iostream>
#include <vector>
using namespace std;

void subsetswithDuplicate(vector<int>& arr, vector<int>& ans, int i, vector<vector<int>>& allSubsets){
    //base case 
    if(i==arr.size()){
        //store subsets
        allSubsets.push_back(ans);
        return;
    }
    //include
    ans.push_back(arr[i]);
    subsetswithDuplicate(arr, ans, i+1, allSubsets);
    
    ans.pop_back();//backtracting

    //exclude
    int idx=i+1;
    //skipping the duplicate values 
    while(idx<arr.size() && arr[idx]==arr[idx-1]){
        idx++;
    }
    subsetswithDuplicate(arr, ans, idx, allSubsets);
}

int main(){
    vector<int> arr = {1,2,2};
    vector<vector<int>> allSubsets;
    
    vector<int> ans; //storing subsets

    subsetswithDuplicate(arr, ans, 0, allSubsets);
     // Print all subsets
    for(int i = 0; i < allSubsets.size(); i++) {
        cout << "{ ";
        for(int num : allSubsets[i]) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}