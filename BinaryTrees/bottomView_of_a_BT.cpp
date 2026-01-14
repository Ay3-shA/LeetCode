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

//bottom view of a binary tree
void bottomView(Node* root){

    if(root == NULL){
        return;
    }

    queue<pair<Node*, int>> q;
    map<int, int> m;
    q.push({root, 0});

    while(q.size()>0){
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();

        m[currHD] = curr->data;

        if(curr->left!=NULL){
            q.push({curr->left, currHD-1});
        }
        if(curr->right!=NULL){
            q.push({curr->right, currHD+1});
        }
    }

    for(auto it : m){
        cout<<it.second<<" ";
    }
}

int main(){
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preOrder);

    

    return 0;
}