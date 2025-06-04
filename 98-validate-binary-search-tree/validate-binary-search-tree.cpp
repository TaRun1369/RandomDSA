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
    bool sorted(vector<int> v){
        int n = v.size();
        for(int i = 1;i<n;i++){
            if(v[i] <= v[i-1]) return false;
        }
        return true;
    }
    void inorder(TreeNode* node,vector<int> &ans){
        if(node== NULL) return;

        inorder(node->left,ans);
        ans.push_back(node->val);
        inorder(node->right,ans);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);

        if(sorted(ans) == true) return true;
        else return false;
    }
};