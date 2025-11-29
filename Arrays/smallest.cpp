#include<iostream>
using namespace std;

int main (){
    int nums[]={5, 15, 22, 1, -15, 24};
    int smallest=INT_MAX;
    int size=6;

    for(int i=0; i<size; i++){
        if(nums[i]<smallest){
            smallest=nums[i];
        }
    }
    cout<<"Smallest number in an array is : "<<smallest;

    return 0;
}