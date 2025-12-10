#include<iostream>
#include<vector>
using namespace std;

int singleElement (vector<int> A){
    int start=0, n=A.size(), end = n-1;

    if(n==1){
        return A[0];
    }
    
    while (start<=end){
        int mid = start + (end-start)/2;
        if(mid==0 && A[0]!=A[1]){
            return A[mid];
        }
        if(mid==n-1 && A[n-1]!=A[n-2]){
            return A[mid];
        }

        if (A[mid-1]!=A[mid] && A[mid] != A[mid+1]){
            return mid;
        }
        if (mid%2==0){//even
            if(A[mid-1]=A[mid]){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        else{//odd
            if(A[mid-1]==A[mid]){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
    }
    return -1;
}

int main(){

    vector<int> A = {1, 1, 2, 2, 3, 3, 4, 4, 5, 8, 8};
    int ans = A[singleElement(A)];
    cout<<"Single Element is "<<ans<<" on index "<<singleElement(A)<<endl;
    return 0;
}