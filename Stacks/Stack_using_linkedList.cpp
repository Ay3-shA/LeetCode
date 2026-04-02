#include<iostream>
#include<list>
using namespace std;

class Stack{
    list<int> ll;
    public:

    void push(int val){ //0(1)
        ll.push_front(val);
    }

    void pop(){ //0(1)
        ll.pop_front();
    }

    int top(){
        return ll.front();
    }

    bool empty(){
        return ll.size() == 0;
    }

};

int main(){
    Stack s;
    s.push(20);
    s.push(30);
    s.push(50);

    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    return 0;
}