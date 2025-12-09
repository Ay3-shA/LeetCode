#include<iostream>
#include<vector>
using namespace std;

int binarySearch (vector<int> arr, int target, int start, int end){
    if(start<=end){
        int mid = start + (end-start)/2;
        if(target > arr[mid]){
            return binarySearch(arr, target, mid+1, end);
        }
        else if(target<arr[mid]){
            return  binarySearch(arr, target, start, mid-1);;
        } 
        else{
            return mid;
        }
    }
    return -1;
}

int main(){

    vector<int> arr = {-1, 0, 3, 4, 5, 8, 9 ,12};
    int target = 12;
    // int start=0, end=arr.size()-1;

    cout<<binarySearch(arr, target, 0, arr.size()-1)<<endl;
    return 0;
}