#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

class minStack{
public:
    stack<pair<int, int>> s;

    void push(int val){
        if(s.empty()){
            s.push({val, val});
        } else {
            int minVal = min(val, s.top().second);
            s.push({val, minVal});
        }
    }

    void pop(){
        if(!s.empty()){
            s.pop();
        }
    }

    int top(){
        return s.top().first;
    }

    int getMin(){
        return s.top().second;
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