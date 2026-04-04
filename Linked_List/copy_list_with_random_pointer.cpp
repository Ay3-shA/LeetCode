#include<iostream>
#include<unordered_map>
using namespace std;

class Node{

    public:
    int data;
    Node* next;
    Node* random;
    //constructor
    Node(int val){
        data = val;
        next = NULL;
        random = NULL;
    }
};

class List{

    Node* head;
    Node* tail;

    public:
    List(){
        head = tail = NULL;
    }

    Node* copyRandomList(Node* head){
        //base case 
        if(head == NULL){
            return NULL;
        }

        unordered_map<Node*, Node*> m;

        Node* newHead = new Node(head->data);

        Node* oldTemp = head->next;
        Node* newTemp = newHead;
        m[head]=newHead;

        while(oldTemp!=NULL){
            Node* copyNode = new Node(oldTemp->data);
            m[oldTemp] = copyNode;
            newTemp->next = copyNode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        //copy random pointers

        oldTemp = head;
        newTemp = newHead;

        while(oldTemp!=NULL){
            if(oldTemp->random != NULL){
            newTemp->random = m[oldTemp->random];
        } else {
            newTemp->random = NULL;
        }

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;

    }

};

int main(){

    // Create nodes
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    // next pointers
    n1->next = n2;
    n2->next = n3;

    // random pointers
    n1->random = n3; // 1 → 3
    n2->random = n1; // 2 → 1
    n3->random = n2; // 3 → 2

    List ll;

    Node* copy = ll.copyRandomList(n1);

    // print copied list
    Node* temp = copy;
    while(temp != NULL){
        cout << temp->data << " ";
        if(temp->random != NULL)
            cout << "(" << temp->random->data << ") ";
        else
            cout << "(NULL) ";

        temp = temp->next;
    }

    return 0;
}