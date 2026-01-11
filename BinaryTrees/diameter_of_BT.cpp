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

//height of a tree
int height(Node* root){
    //base case
    if(root == NULL){
        return 0;
    }

    int left_height = height(root->left);
    int right_height = height(root->right);

    return max(left_height, right_height)+1;
}

int diameter(Node* root){
    //base case
    if (root == NULL){
        return 0;
    }

    //lh+rh
    //ld
    //rd

    int left_diam = diameter(root->left);
    int right_diam = diameter(root->right);

    int curr_diam = height(root->left)+height(root->right);

    return max(left_diam, max(right_diam, curr_diam));
}

int main(){
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preOrder);

    cout<<diameter(root);

    return 0;
}