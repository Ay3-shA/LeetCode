#include<iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    bool isIdentical(TreeNode* p, TreeNode* q) {
        // base case
        if (p == NULL || q == NULL) {
            return p == q;
        }

        return p->data == q->data 
        && isIdentical(p->left, q->left)
        && isIdentical(p->right, q->right);

    }

    bool isSubTree(TreeNode* root, TreeNode* subRoot){
        if(root == NULL || subRoot == NULL){
            return root == subRoot;
        }
        if(root->data == subRoot->data && isIdentical(root, subRoot)){
            return true;
        }

        return isSubTree(root->left, subRoot) || isSubTree(root->right, subRoot);
    }
};

int main() {
    // Tree 1
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->right->left = new TreeNode(4);
    p->right->right = new TreeNode(5);

    // Tree 2
    TreeNode* q = new TreeNode(3);
    q->left = new TreeNode(4);
    q->right = new TreeNode(5);

    Solution s;
    s.isIdentical(p, q);
    bool result = s.isSubTree(p, q);
    cout<<result;
    return 0;
}
