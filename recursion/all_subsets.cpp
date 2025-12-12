#include <iostream>
#include <vector>
using namespace std;

void printSubsets(vector<int>& arr, vector<int>& ans, int i){
    //base case 
    if(i==arr.size()){
        for(int val : ans){
            cout<<val<<" ";
        }
        cout<<endl;
        return;
    }
    //include
    ans.push_back(arr[i]);
    printSubsets(arr, ans, i+1);
    
    ans.pop_back();//backtracting
    printSubsets(arr, ans, i+1);//exclude
}

int main(){
    vector<int> arr = {1,2,3};
    vector<int> ans; //storing subsets

    printSubsets(arr, ans, 0);

    return 0;
}