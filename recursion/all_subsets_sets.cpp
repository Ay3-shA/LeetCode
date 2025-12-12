#include <iostream>
#include <vector>
using namespace std;

void printSubsets(vector<int>& arr, vector<int>& ans, int i, vector<vector<int>>& allSubsets){
    //base case 
    if(i==arr.size()){
        //store subsets
        allSubsets.push_back(ans);
        return;
    }
    //include
    ans.push_back(arr[i]);
    printSubsets(arr, ans, i+1, allSubsets);
    
    ans.pop_back();//backtracting
    printSubsets(arr, ans, i+1, allSubsets);//exclude
}

int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> allSubsets;
    
    vector<int> ans; //storing subsets

    printSubsets(arr, ans, 0, allSubsets);
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