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

void printPreOrder( Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
    
}

//transform to sum tree
int sumTree(Node* root){
    //base case
    if(root == NULL){
        return 0;
    }

    int left_Sum = sumTree(root->left);
    int right_Sum = sumTree(root->right);

    root->data += left_Sum + right_Sum;

    return root->data; 
}

int main(){
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preOrder);
    
    cout<<"Before Conversion: ";
    printPreOrder(root);
    cout<<endl;

    sumTree(root);

    cout<<"After Conversion: ";
    printPreOrder(root);
    cout<<endl;

    return 0;
}