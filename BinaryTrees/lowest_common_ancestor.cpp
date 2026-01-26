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

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> preOrder){
    idx++;

    if(preOrder[idx]==-1){
        return NULL;
    }

    Node* root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);

    return root;
}

//Lowest Common Ancestor
Node* LowestCommonAncestor(Node* root, Node* p, Node* q){
    if(root==NULL){
        return NULL;   // FIX
    }
    if(root->data == p->data || root->data == q->data){
        return root;
    }

    Node* leftLCA = LowestCommonAncestor(root->left, p, q);
    Node* rightLCA = LowestCommonAncestor(root->right, p, q);

    if(leftLCA && rightLCA){
        return root;
    }else if(leftLCA!=NULL){
        return leftLCA;
    }else{
        return rightLCA;
    }
}

int main(){
    vector<int> preOrder = {1,2,4,-1,-1,5,8,-1,-1,9,-1,-1,3,6,-1,-1,7,-1,-1};

    Node* root = buildTree(preOrder);

    Node* p = root->left;        //2
    Node* q = root->left->right;  //5

    Node* ans = LowestCommonAncestor(root, p, q);
    cout << ans->data << endl;

    return 0;
}
