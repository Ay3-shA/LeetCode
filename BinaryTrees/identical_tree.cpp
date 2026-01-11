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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // base case
        if (p == NULL || q == NULL) {
            return p == q;
        }

        bool isLeftSame = isSameTree(p->left, q->left);
        bool isRightSame = isSameTree(p->right, q->right);

        return isLeftSame && isRightSame && (p->data == q->data);
    }
};

int main() {
    // Tree 1
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Tree 2
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution s;
    bool result = s.isSameTree(p, q);

    // Print result
    if (result)
        cout << "Trees are same." << endl;
    else
        cout << "Trees are NOT same." << endl;

    return 0;
}
