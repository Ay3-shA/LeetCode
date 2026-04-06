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
            if(temp=NULL){
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
    return 0;
}