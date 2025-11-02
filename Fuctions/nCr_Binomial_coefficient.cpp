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

int nCr(int n, int r){
    int fact_n=factorial(n);
    int fact_r=factorial(r);
    int fact_nmr=factorial(n-r);

    int fact_ncr= fact_n/(fact_r*fact_nmr);


    return fact_ncr;
}

int main(){
    int n=8, r=4;
    cout<<nCr(n, r);
    return 0;
}