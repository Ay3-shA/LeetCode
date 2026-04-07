#include<iostream>
#include<unordered_map>
using namespace std;

class LRUCache{
public:

    class Node{
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v){
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    Node* head;
    Node* tail;

    unordered_map<int, Node*> m;
    int limit;

    LRUCache(int capacity){
        limit = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode){ // add after head
        Node* oldNext = head->next;

        head->next = newNode;
        newNode->prev = head;

        newNode->next = oldNext;
        oldNext->prev = newNode;
    }

    void deleteNode(Node* oldNode){
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    int get(int key){
        if(m.find(key) == m.end()){
            return -1;
        }

        Node* node = m[key];
        int ans = node->val;

        deleteNode(node);
        addNode(node);

        return ans;
    }

    void put(int key, int val){

        if(m.find(key) != m.end()){
            Node* oldNode = m[key];
            deleteNode(oldNode);
            m.erase(key);
        }

        if(m.size() == limit){
            Node* lru = tail->prev;
            m.erase(lru->key);
            deleteNode(lru);
        }

        Node* newNode = new Node(key, val);
        addNode(newNode);
        m[key] = newNode;
    }
    
};


int main(){

    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cout << cache.get(1) << endl; // 10

    cache.put(3, 30); // removes key 2

    cout << cache.get(2) << endl; // -1

    cache.put(4, 40); // removes key 1

    cout << cache.get(1) << endl; // -1
    cout << cache.get(3) << endl; // 30
    cout << cache.get(4) << endl; // 40

    return 0;
}