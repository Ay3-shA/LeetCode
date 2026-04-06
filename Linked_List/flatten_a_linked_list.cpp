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
    Node* flatten(Node* head){
        if(head == NULL){
            return head;
        }

        Node* curr = head;
        while (curr!=NULL){
            if(curr->child != NULL){
                //flatten the child nodes
                Node* next = curr->next;
                curr->next = flatten(curr->child);

                curr->next->prev = curr;
                curr->child = NULL;

                //find tail
                while(curr->next != NULL){
                    curr = curr->next;
                }

                //attach tail with next ptr
                if(next!=NULL){
                    curr->next = next;
                    next->prev = curr;
                }
            }

            curr = curr->next;

        }
        return head;
    }

};

int main(){

    // 1 <-> 2 <-> 3 <-> 4 <-> 5
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    head->next = n2; n2->prev = head;
    n2->next = n3;   n3->prev = n2;
    n3->next = n4;   n4->prev = n3;
    n4->next = n5;   n5->prev = n4;

    // 6 <-> 7 <-> 8 (child of 3)
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);

    n6->next = n7; n7->prev = n6;
    n7->next = n8; n8->prev = n7;

    n3->child = n6;

    // 9 <-> 10 (child of 7)
    Node* n9 = new Node(9);
    Node* n10 = new Node(10);

    n9->next = n10; n10->prev = n9;

    n7->child = n9;

    solution s;
    head = s.flatten(head);

    // print
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL";

    return 0;
    
}