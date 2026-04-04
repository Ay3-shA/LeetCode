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

    
    //----------------------------------------

    Node* mergeTwoLists(Node* head1, Node* head2){
        //base case
        if(head1 == NULL || head2 == NULL){
            return head1 == NULL ? head2 : head1; 
        }
        //case1
        if(head1->data <= head2->data){
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        }else{
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }

    //----------------------------------------

};



int main (){

    //First sorted list: 1->3->5
    Node* head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);

    //Second sorted list: 2->3->6
    Node* head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(6);

    List ll;

    Node* merged = ll.mergeTwoLists(head1, head2);

    Node* temp = merged;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";

    return 0;
}