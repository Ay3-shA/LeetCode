//Analyse the following program and determine its complexity. for each line (or block) of code, clearly state its cost T(n). Show how you derive the overall time function T(n) and determine the tight Big-O complexity for worst case scenario. Explain your reasoning briefly in one line. 

#include<iostream>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot=arr[high];
    int i=low;

    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

int quickSelectIterative(int arr[], int n, int k){
    int low=0, high=n-1;

    while(low<=high){
        int pi=partition(arr, low, high);

        if(pi==k-1)
        return arr[pi];
        else if (pi>k-1)
        high=pi-1;
        else
        low=pi+1;
    }
    return -1;
}
