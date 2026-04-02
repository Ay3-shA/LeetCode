#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

class minStack{
public:
    stack<long long> s;
    long long int minVal;

    void push(int val){
        if(s.empty()){
            s.push(val);
            minVal = val;
        } else {
            if(val < minVal){
                s.push((long long)2*val - minVal); 
                minVal = val;
            } else {
                s.push(val);
            }
        }
    }

    void pop(){
        if(s.top() < minVal){
            minVal = 2*minVal - s.top();
        }

        s.pop();
    }

    int top(){
        if(s.top() < minVal){
            return minVal;
        }
        return s.top();
    }

    int getMin(){
        return minVal;
    }
};

int main (){

    minStack ms;

    ms.push(-2);
    ms.push(0);
    ms.push(-3);

    cout << ms.getMin() << endl; // -3

    ms.pop();

    cout << ms.top() << endl;    // 0
    cout << ms.getMin() << endl; // -2
    
    return 0;
}