// You are given the root of a binary tree that consists of exactly 3 nodes: the root, its left child, and its right child.
// Return true if the value of the root is equal to the sum of the values of its two children, or false otherwise.

class Solution {
public:
    bool checkTree(TreeNode* root) {
        if(root==nullptr){
            return false;
        }
        int baap=root->val;
        int lkid=root->left->val;
        int rkid=root->right->val;
        if(baap==(lkid+rkid)){
            return true;
        }
        return false;
    }
};
