#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main (){
    vector<int> nums={1, 2, 2, 1, 1};
    int n=nums.size();
    //sorting 
    sort(nums.begin(), nums.end());
    cout<<"Sorted Array is: ";
    for(int x : nums){
        cout << x << " ";
    }
    cout << endl;

    // find most frequent
    int currFreq = 1;
    int maxFreq = 1;
    int ans = nums[0];

    for(int i=1; i<n; i++){
        if(nums[i] == nums[i-1]){
            currFreq++;
        }
        else{
            currFreq = 1;
        }

        if(currFreq > maxFreq){
            maxFreq = currFreq;
            ans = nums[i];
        }
    }

    cout << "Most frequent = " << ans;
    return 0;
}