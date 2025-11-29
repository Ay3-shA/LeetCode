#include<iostream>
using namespace std;

int main(){
    int num=32;
    int n=num;

    if (num>0 && (num&(num-1))==0){
        cout<<n<<" is power of 2."<<endl;
    }
    else {
        cout<<n<<" is not power of 2."<<endl;
    }

    // if (num>0){
    //     while(num%2==0){
    //         num=num/2;
    //     }
    //     if(num==1){
    //         cout<<n<<" is the power of 2."<<endl;
    //     }
    // }

    // if(num==0 || num!=1 ){
    //         cout<<n<<" is not the power of 2."<<endl;
    //     }

    return 0;
}