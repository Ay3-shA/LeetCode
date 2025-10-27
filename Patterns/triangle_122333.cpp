#include<iostream>
using namespace std;
int main(){

    int n = 3;
    for (int i=0; i<n; i++){
        for (int j=1; j<i+2; j++){
            cout<<i+1;
        }
        cout<<endl;
    }

    return 0;
}