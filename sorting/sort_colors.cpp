//one-pass algorithm ... array py aik dafa pass kiya hy aik loop laga k .. then dusri dafa pass kiya hy baqi loop laga k ..
//thats why its optimized .. we can have more optimized code as well ..  

#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int>& nums){
    int n = nums.size();
    int count0 = 0, count1 = 0, count2 = 0;

    //O(n)
    for(int i=0;i<n;i++){
        if(nums[i]==0){
            count0++;
        }
        else if(nums[i]==1){
            count1++;
        }
        else{
            count2++;
        }
    }

    int idx = 0;

    for (int i=0;i<count0;i++){
        nums[idx]=0;
        idx++;
    }
    for (int i=0;i<count1;i++){
        nums[idx]=1;
        idx++;
    }
    for (int i=0;i<count2;i++){
        nums[idx]=2;
        idx++;
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
    sortColors(nums);
    printArray(nums);
    return 0;
}