#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& arr, int start, int mid, int end){
    vector<int> temp;
    int i = start, j = mid+1;
    int inversionCount=0;

    while (i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
            inversionCount =+ (mid - i + 1);
        }
    }

    while (i<=mid){
        temp.push_back(arr[i]);
        i++;
    }

    while (j<=end){
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx=0; idx<temp.size(); idx++){
        arr[idx+start] = temp[idx];
    }

    return inversionCount;
}

int mergeSort(vector<int>& arr,int start, int end){
    if (start<end){
        int mid = start + (end - start)/2;
    
        int leftInvCount = mergeSort(arr, start, mid); //left count
        int rightInvCount = mergeSort(arr, mid+1, end); //right count

        int invCount = merge(arr, start, mid, end);

        return leftInvCount + rightInvCount + invCount;
   }

   return 0;
    
}

int main(){

    vector<int> arr = {6, 3, 5, 2, 7};
   // vector<int> arr = {12, 31, 35, 8, 32, 17};

    int result = mergeSort(arr, 0, arr.size()-1);

    cout<<result<<endl;


    return 0;
}