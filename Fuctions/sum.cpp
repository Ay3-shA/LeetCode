#include<iostream>
using namespace std;
//sum of two number
int sum(int a, int b){
    int s=a+b;
    return s;
}
//min of two number
int minOfNum(int c, int d){
    if (c<d){
        return c;
    }else{
        return d;
    }
}

int main (){
    cout<<sum(10, 5)<<endl;
    cout<<minOfNum(8, 2)<<endl;
    return 0;
}