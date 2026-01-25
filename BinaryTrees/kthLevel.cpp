#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;

    //constructor 

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> preOrder){
    idx++;

    //Base case
    if(preOrder[idx]==-1){
        return NULL;
    }


    Node* root = new Node(preOrder[idx]);

    root->left = buildTree(preOrder); //LEFT SUBTREE
    root->right = buildTree(preOrder); //RIGHT SUBTREE

    return root;

}

//kth level of a binary tree
void kthLevel(Node* root, int K){
    //base case
    if(root==NULL){
        return;
    }
    if(K==1){
        cout<<root->data<<"  ";
        return;
    }

    kthLevel(root->left, K-1);
    kthLevel(root->right, K-1);

}

int main(){
    vector<int> preOrder = {1, 2, 7, -1, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preOrder);

    kthLevel(root, 3);

    return 0;
}