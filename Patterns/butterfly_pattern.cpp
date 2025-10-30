#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a Number: ";
    cin>>n;

    for(int i=0;i<n;i++){
        
        for(int j=0;j<i+1;j++){
            cout<<"*";
        }
        
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        
        for(int j=0;j<i+1;j++){
            cout<<"*";
        }
        
        cout<<endl;
    }
    int k;
    if(n%2==0){
        //even -- 2 middle lines
        k=0;
        //cout<<"even -- 2 middle lines"<<endl;
    }else{
        //odd -- one middle line
        k=1;
        //cout<<"odd -- 1 middle line"<<endl;
    }
    for(int i=k;i<n;i++){
        
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        
        cout<<endl;
    }

    return 0;
}


