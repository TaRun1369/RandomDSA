/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool symm(TreeNode* lef,TreeNode* rig){
        if(lef == NULL && rig == NULL) return true;
        if(lef == NULL || rig == NULL) return false;
        return (lef->val == rig->val) && symm(lef->right,rig->left) && symm(lef->left,rig->right);
    }
    bool isSymmetric(TreeNode* root) {
        return symm(root->left,root->right);
    }
};