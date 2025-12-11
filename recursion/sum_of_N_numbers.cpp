#include <iostream>
using namespace std;

int sumN(int n){
    //Base Case
    if(n==1){
        return 1;
    }
    return n + sumN(n-1);
}

int main(){
    cout<<sumN(4)<<endl;
    return 0;
}