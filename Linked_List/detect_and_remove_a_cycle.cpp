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

    void makeCycleAtPos(int pos){
    if(head == NULL) return;

    Node* temp = head;
    Node* cycleNode = NULL;
    int count = 1;

    while(temp->next != NULL){
        if(count == pos){
            cycleNode = temp;
        }
        temp = temp->next;
        count++;
    }

    // temp is now at tail
    if(cycleNode != NULL){
        temp->next = cycleNode; 
    }
}

    //----------------------------------------------------

    Node* detectAndRemoveCycle(){
        Node* slow = head;
        Node* fast = head;

        bool hasCycle = false;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                hasCycle = true;
                break;
            }
        }
        if(!hasCycle){
            return NULL;
        }

        slow = head;
        Node* prev = NULL;
        while(slow!=fast){
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL; //cycle removed
        return slow;
    }

    //----------------------------------------------------


    void printCycle(int limit){
    Node* curr = head;
    int count = 0;

    while(curr != NULL && count < limit){
        cout << curr->data << "->";
        curr = curr->next;
        count++;
    }
    cout << "NULL" << endl;
}
};


int main (){

    List ll;

    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.makeCycleAtPos(3); 

    cout<< ll.detectAndRemoveCycle()->data<<endl;
    ll.printCycle(10);

    return 0;
}