#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int start, int end){
    int idx = start-1; //Less than pivot elements k liye jagah banaye ga.
    int pivot = arr[end];
    //j pury array py iterate kary ga, sary elements ko pivot k sath compare kary ga 
    for(int j=start; j<end; j++){
        if (arr[j]<=pivot){
            idx++;
            swap(arr[j], arr[idx]); 
        }
    }
    idx++;
    swap(arr[end], arr[idx]);
    return idx;  
}

void quickSort(vector<int>& arr, int start, int end){
    if(start<end){
        int pivIdx = partition(arr, start, end); 
        quickSort(arr, start, pivIdx-1);//left half 
        quickSort(arr, pivIdx+1, end);//right half
    }
    return;
}

int main (){

    vector<int> arr = {12, 31, 35, 8, 32, 17};
    quickSort(arr, 0, arr.size()-1);

    for (int val : arr){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}