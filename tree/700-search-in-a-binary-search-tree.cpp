// You are given the root of a binary search tree (BST) and an integer val.
// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==nullptr){
            return NULL;
        }
        if(root->val==val){
            return root;
        }
        TreeNode* left=root->left;
        TreeNode* right=root->right;
        if(val<root->val){
            return searchBST(left,val);
        }
        if(val>root->val){
            return searchBST(right,val);
        }
        return root;
    }
};
