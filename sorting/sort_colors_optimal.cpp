//Dutch National Flag Algorithm  
//one-pass algorithm

#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int>& nums, int low, int mid, int high){
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[mid], nums[low]);
            mid++;
            low++;
        }else if(nums[mid]==1){
            mid++;
        }else{
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

void printArray(vector<int> nums){
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> nums = {2, 0, 2, 1, 1, 0, 1, 2 , 0, 0};
    sortColors(nums, 0, 0, nums.size()-1);
    printArray(nums);
    return 0;
}