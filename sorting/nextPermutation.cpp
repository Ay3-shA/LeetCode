#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutuion(vector<int>& A){
    //Find Pivot
    int pivot = -1, n = A.size();

    for(int i=n-2; i>=0; i--){
        if(A[i] < A[i+1]) {
            pivot = i;
            break;
        }
    }

    if(pivot == -1){
        reverse(A.begin(), A.end()); //in place changes
        return;
    }

    //2nd step: next larger element
    for(int i=n-1;i>pivot;i--){
        if(A[i]>A[pivot]){
            swap(A[i], A[pivot]);
            break;
        }
    }

    //3rd step: reverse (pivot+1 to n-1)

    //reverse(A.begin() + pivot + 1, A.end());

    int i=pivot+1, j = n-1;
    while(i<=j){
        swap(A[i++], A[j--]);
    }
}

void printArray(vector<int> A){
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> A = {1, 2, 5, 4, 3};

    nextPermutuion(A);
    printArray(A);

    return 0;
}