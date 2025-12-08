#include<iostream>
#include<vector>
using namespace std;

void reverseArray(vector<int>& nums, int n){

    int start=0, end=n-1; 
    while(start<end){
        swap(nums[start], nums[end]);
        start++; end--;
    }
}

int main (){

    vector<int> nums = {4, 2, 7, 8, 1, 2, 5};
    int n=nums.size();

    cout<<"Original Array is : ";
    for (int i =0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    reverseArray(nums, n);

    cout<<"Reversed Array is : ";
    for (int i =0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}