#include <iostream>
#include <vector>
using namespace std;

//helper function 
int binSearch(vector<int> arr, int target, int start, int end){
    if(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            return binSearch(arr, target, start, mid-1);
        }
        else{
            return binSearch(arr, target, mid+1, end);
        }
    }
    return -1;
}
//main function 
int Search(vector<int> arr, int target){
    return binSearch(arr, target, 0, arr.size()-1);
}

int main(){
    vector<int> arr = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    cout << Search(arr, target);

    return 0;
}