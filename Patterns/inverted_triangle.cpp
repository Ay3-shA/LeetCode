#include<iostream>
using namespace std;
int main(){
    int n=4;
    // int num=1;
    //outer loop for no. of lines 
    for (int i=0;i<n;i++){
        //print spaces
        for(int j=0; j<i; j++){
            cout<<" ";
        }
        //print numbers
        for(int j=0; j<n-i; j++){
            cout<<(i+1);
        }
        cout<<endl;
    }
    
    return 0;
}
