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

class solution{
    public:

    void allPaths(Node* root, string path, vector<string> &ans){
        if (root->left==NULL && root->right==NULL){
            ans.push_back(path);
            return;
        }

        if(root->left){
            allPaths(root->left, path+"->"+to_string(root->left->data), ans);
        }

        if(root->right){
            allPaths(root->right, path+"->"+to_string(root->right->data), ans);
        }
    }

    vector<string> binaryTreePaths(Node* root){
        vector<string> ans;
        string path = to_string(root->data);

        allPaths(root, path, ans);
        return ans;
    }
};

int main(){
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preOrder);

    solution obj;
    vector<string> result = obj.binaryTreePaths(root);

    // print result
    for(string s : result){
        cout << s << endl;
    }

    return 0;
}