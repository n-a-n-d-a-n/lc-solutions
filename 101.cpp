// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        return isMirror(root->left,root->right);
    }
private:
    bool isMirror(TreeNode* t1,TreeNode* t2){
        if(t1==nullptr&&t2==nullptr){
            return true;
        }
        if(t1==nullptr||t2==nullptr||t1->val!=t2->val){
            return false;
        }
        return isMirror(t1->left,t2->right)&&isMirror(t1->right,t2->left);
    }
};
