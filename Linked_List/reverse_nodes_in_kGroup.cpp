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

class Solution{
    public:
    Node* reverseKGroup(Node* head, int k){
        Node* temp = head;
        int cnt = 0;
        //check if k nodes exist
        while(cnt<k){
            if(temp==NULL){
                return head;
            }
            temp = temp->next;
            cnt++;
        }
        //recursively call for rest of LL
        Node* prevNode = reverseKGroup(temp, k);
        //reverse current group 
        temp = head; cnt = 0;
        while(cnt<k){
            Node* next = temp->next;
            temp->next = prevNode;

            prevNode = temp;
            temp = next;

            cnt++;
        }
        return prevNode;
    }
};

int main(){

    // create list: 1->2->3->4->5->6
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;

    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;

    int k = 2;

    Solution s;
    head = s.reverseKGroup(head, k);

    // print result
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";

    return 0;
}