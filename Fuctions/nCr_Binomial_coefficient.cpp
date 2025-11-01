#include<iostream>
using namespace std;

    //Calculate n!
void fact(int n){
    int lastDigit=0;
    while(n>0){
        lastDigit+=n%10;
        n=n/10;
        int digitSum =+ lastDigit;
    }
    
}

int main(){
    int n=4;
    cout<<fact;

    return 0;
}