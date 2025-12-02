#include<iostream>
using namespace std;

int main(){

    int arr[]={1, 2, 3, 3, 1, 2, 4};
    int size=8, unique=0;

    for (int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i]!=arr[j]){
                unique=arr[i];
            }
        }
        cout<<"unique number is/are : "<<unique<<endl;
    }
    return 0;
}