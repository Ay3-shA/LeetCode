#include<iostream>
#include<queue>
using namespace std;

class MyStack{
    public:
    queue<int> q1;
    queue<int> q2;

    MyStack(){

    }

    void push(int x){ // O(n)
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(x);

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();  // FIXED
        }
    }

    int pop(){
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    int top(){
        return q1.front();
    }

    bool empty(){
        return q1.empty();
    }
};

int main(){
    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;   // should be 30

    cout << "Popped: " << st.pop() << endl;        // removes 30
    cout << "Top element: " << st.top() << endl;   // should be 20

    cout << "Popped: " << st.pop() << endl;        // removes 20
    cout << "Popped: " << st.pop() << endl;        // removes 10

    cout << "Is empty? " << st.empty() << endl;    // should be 1 (true)

    return 0;
}