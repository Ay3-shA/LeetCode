#include<iostream>
#include<vector>
using namespace std;

int peakSearch (vector<int> A){
    int start=1, end = A.size()-2;
    
    while (start<=end){
        int mid = start + (end-start)/2;
        if (A[mid-1]<A[mid] && A[mid]>A[mid+1]){
            return mid;
        }
        else if (A[mid-1]<A[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}

int main(){

    vector<int> A = {0, 3, 8, 9, 5, 2};
    int ans = A[peakSearch(A)];
    cout<<"Peak Element is "<<ans<<" on index "<<peakSearch(A)<<endl;
    return 0;
}