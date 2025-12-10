#include<iostream>
#include<vector>
using namespace std;

int rotatedSearch (vector<int> arr, int target){
    int start=0, end = arr.size()-1;
    
    while (start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[start]<=arr[mid]){
            //left sorted
            if(arr[start]<=target && target <=arr[mid]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        else{ //right sorted
            if(arr[mid]<=target && target <=arr[end]){
                start = mid+1;
            }
            else{
                end=mid-1;
            }
        }
    }
    return -1;
}

int main(){

    vector<int> arr = {3, 4, 5, 6, 7, 0, 1, 2};
    int target = 6;
    // int start=0, end=arr.size()-1;

    cout<<rotatedSearch(arr, target)<<endl;
    return 0;
}