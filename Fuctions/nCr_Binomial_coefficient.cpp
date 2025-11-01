#include<iostream>
using namespace std;

    //Calculate Factorial 
int factorial(int n){
    int fact = 1;
    for(int i=1;i<=n;i++){
        fact*=i;
    }
    return fact;
    
}

int main(){
    cout<<factorial(4);
    return 0;
}