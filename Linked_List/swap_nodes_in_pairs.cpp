#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node* child;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
        child = NULL;
    }
};

class solution{
    public:
    Node* swapPairs(Node* head){
        if(head == NULL || head->next == NULL){
            return head;
        }

        Node* first = head;
        Node* sec = head->next;
        Node* prev = NULL;

        while(first!=NULL && sec!=NULL){
            Node* third = sec->next;

            sec->next = first;
            first->next = third;

            if(prev!=NULL){
                prev->next = sec;
            }else{
                head = sec;
            }

            //update
            prev = first;
            first = third;
            if(third!=NULL){
                sec = third->next;
            }else{
                sec=NULL;
            }
        }
        return head;
    }
};

int main(){

    // create list: 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    solution s;
    head = s.swapPairs(head);

    // print result
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";

    return 0;
}

