#include<iostream>
#include<vector>
using namespace std;

int binarySearch (vector<int>& arr1, int target){
    int n=arr1.size();
    int start=0, end=n-1;
    while (start<=end){
        int mid = (start + ((end-start)/2));
        if(target > arr1[mid]){
            start = mid + 1;
        }
        else if(target<arr1[mid]){
            end=mid-1;
        } 
        else{
            return mid;
        }
    }
    return -1;
}

int main(){

    vector<int> arr1 = {-1, 0, 3, 4, 5, 8, 9 ,12};
    int target = 9;

    cout<<binarySearch(arr1, target);
    return 0;
}