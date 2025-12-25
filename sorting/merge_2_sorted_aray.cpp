#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& A, int m, vector<int>& B, int n){
    int i = m-1, j = n-1, idx = m+n-1;
    while(i>=0 && j>=0){
        if (A[i]<B[j]){
            A[idx--] = B[j--];
        }
        else{
            A[idx--]=A[i--];
        }
    }
    while (j>=0){
        A[idx--] = B[j--];
    }
}

void printArray(vector<int> A){
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> A = {1, 2, 3, 0, 0, 0};
    int m=3;
    vector<int> B = {2, 5, 6};
    int n=3;

    merge(A, m, B, n);
    printArray(A);

    return 0;
}