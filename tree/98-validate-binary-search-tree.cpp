// Given the root of a binary tree, determine if it is a valid binary search tree (BST).
// A valid BST is defined as follows:
// The left subtree of a node contains only nodes with keys strictly less than the node's key.
// The right subtree of a node contains only nodes with keys strictly greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

class Solution {
public:
    bool isValidBST(TreeNode* root,long long minVal=LONG_MIN,long long maxVal=LONG_MAX){
        if(root==nullptr){
            return true;
        }
        if(root->val<=minVal||root->val>=maxVal){
            return false;
        }
        return isValidBST(root->left,minVal,root->val)&&isValidBST(root->right,root->val,maxVal);
    }
};
