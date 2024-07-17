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
//  map<int ,TreeNode*> mp;
 vector<TreeNode*> ans;
 int left = 1;
 TreeNode*  dfs(TreeNode* root,set<int> del){
    if(root == NULL) return NULL;

    root->left = dfs(root->left,del);
    root->right  = dfs(root->right,del);

    if(del.find(root->val) != del.end()){
        if(root->left != NULL) ans.push_back(root->left);
        if(root->right != NULL) ans.push_back(root->right);
         return NULL;

    }
    else{
        return root;
    }



 }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> del(to_delete.begin(),to_delete.end());
        dfs(root,del);
        if(del.find(root->val) == del.end()){
            ans.push_back(root);
        }
        return ans; 
    }
};