#include<iostream>
using namespace std;

int primeNo(int n){
    bool isPrime=true;

    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            isPrime=false;
            break;
        }
    }
    if (isPrime==true){
        cout<<"Prime Number\n";
    }
    else if(isPrime==false)
    {
        cout<<"Non Prime Number\n";
    }
    return isPrime;
}

int main (){
    primeNo(9);
    return 0;
}