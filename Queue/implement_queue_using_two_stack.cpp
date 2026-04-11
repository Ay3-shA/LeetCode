#include<iostream>
#include<stack>
using namespace std;

class MyQueue{
    public:
    stack<int> s1;
    stack<int> s2;

    MyQueue(){

    }

    void push(int x){ // O(n)
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();  // FIXED
        }
    }

    int pop(){
        int ans = s1.top();
        s1.pop();
        return ans;
    }

    int peek(){
        return s1.top();
    }

    bool empty(){
        return s1.empty();
    }
};

int main() {
    MyQueue q;

    // Push elements
    q.push(10);
    q.push(20);
    q.push(30);

    // Peek front element
    cout << "Front element: " << q.peek() << endl;

    // Pop elements
    cout << "Popped: " << q.pop() << endl;
    cout << "Popped: " << q.pop() << endl;

    // Check front again
    cout << "Front element: " << q.peek() << endl;

    // Check if empty
    cout << "Is empty? " << q.empty() << endl;

    // Pop last element
    cout << "Popped: " << q.pop() << endl;

    // Check again
    cout << "Is empty? " << q.empty() << endl;

    return 0;
}