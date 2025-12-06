#include <iostream>
using namespace std;

int fact(int n){
    //Base Case
    if(n==0){
        cout<<"1\n";
        return;
    }
    cout<<n<<" ";
    return n*fact(n-1);
}

int main(){
    fact(4);
    return 0;
}