#include<iostream>
#include<vector>
#include<queue>
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
    
    int widthOfBinaryTree(Node* root){
        queue<pair<Node*,unsigned long long>> q;

        if(root == NULL) return 0;

        q.push({root,0});
        int maxWidth = 0;

        while(q.size()>0){
            int currLevSize = q.size();

            unsigned long long stIdx = q.front().second;
            unsigned long long endIdx = q.back().second;

            maxWidth = max(maxWidth, (int)(endIdx-stIdx+1));

            for(int i=0; i<currLevSize; i++){
                auto curr = q.front();
                q.pop();

                if(curr.first->left){
                    q.push({curr.first->left, curr.second*2+1});
                }

                if(curr.first->right){
                    q.push({curr.first->right, curr.second*2+2});
                }
            }
        }

        return maxWidth;
    }
};

int main(){
    vector<int> preOrder = {1, 3, 5, -1, -1, 3, -1, -1, 2, -1, 9, -1, -1};

    Node* root = buildTree(preOrder);

    solution obj;
    int result = obj.widthOfBinaryTree(root);

    cout<<result;

    return 0;
}