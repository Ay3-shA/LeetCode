#include<iostream>
#include<vector>
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

//preOrder Traversal

void inOrderTrav(Node* root){

    //base case
    if (root==NULL){
        return;
    }
    inOrderTrav(root->left);
    cout<<root->data<<endl;
    inOrderTrav(root->right);

}

int main(){
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preOrder);
    inOrderTrav(root);

    cout<<endl;

    return 0;
}