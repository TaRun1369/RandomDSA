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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        int par = 0;
        if(root == NULL) return {};
        q.push(root);

        while(!q.empty()){
            int siz = q.size();
            vector<int> lvl;
            for(int i = 0;i<siz;i++){
                TreeNode* top = q.front();q.pop();
                lvl.push_back(top->val);
                if(top->left != NULL) q.push(top->left);
                if(top->right != NULL) q.push(top->right);

            }
            if(par == 1)
            reverse(lvl.begin(),lvl.end());
            par = !par;
            ans.push_back(lvl);
        }

        return ans;

    }
};