#include <iostream>
using namespace std;

int BintoDec(int binNum){
    int rem=0, pow=1, ans=0;

    while(binNum>0){
        rem=binNum%2;
        ans=ans+(rem*pow);
        binNum/=10;
        pow=pow*2;
    }
    return ans;
}

int main (){

    int binNum=1000;
    cout<<BintoDec(binNum)<<endl;

    return 0;
}