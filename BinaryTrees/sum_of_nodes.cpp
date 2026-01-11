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

//sum of nodes
int sum(Node* root){
    //base case
    if(root == NULL){
        return 0;
    }

    int left_sum = sum(root->left);
    int right_sum = sum(root->right);

    return left_sum + right_sum + root->data;
}

int main(){
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preOrder);
    cout<<"sum : "<<sum(root);

    return 0;
}