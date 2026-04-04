#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;
    //constructor
    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{

    Node* head;
    Node* tail;

    public:
    List(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val); //dynamic
        if(head == NULL){
            head = tail = newNode;
            return;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val); //dynamic
        if(head == NULL){
            head = tail = newNode;
            return;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){
        if(head == NULL){
            cout<<"LL is empty\n";
            return;
        }

        if(head == tail){   // only one node
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    void pop_back(){
    if(head == NULL){
        cout<<"LL is empty\n";
        return;
    }

    if(head == tail){   // only one node
        delete head;
        head = tail = NULL;
        return;
    }

    Node* temp = head;
    while(temp->next!=tail){
        temp = temp -> next;
    }
    temp->next = NULL;
    delete tail;
    tail = temp;
    }

    //----------------------------------------------------

    Node* middleNode(){
        Node* slow = head;
        Node* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    //----------------------------------------------------


    void printLL(){
        
        Node* curr = head;
        
        while(curr!=NULL){
            cout<<curr->data<<"->";
            curr = curr -> next;
        }
        cout<<"NULL"<<endl;
    }
};


int main (){

    List ll;

    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.printLL();

    cout<< ll.middleNode()->data;

    return 0;
}