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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        if(root == NULL) return {};
        while(!q.empty()){
            int siz = q.size();
            vector<int> lvl;
            for(int i = 0;i<siz;i++){
                TreeNode* top = q.front();
                q.pop();
                lvl.push_back(top->val);
                if(top->right != NULL)
                    q.push(top->right);
                if(top->left != NULL)
                    q.push(top->left);

            }
            reverse(lvl.begin(),lvl.end());
            ans.push_back(lvl);
        }
        return ans;
    }
};