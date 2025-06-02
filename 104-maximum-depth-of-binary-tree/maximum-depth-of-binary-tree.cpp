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
    
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        if(root == NULL) return 0;
        int lvl = 0;
        while(!q.empty()){
            int siz = q.size();
            for(int i = 0;i<siz;i++){
                TreeNode* top = q.front();
                q.pop();

                if(top->left != NULL) q.push(top->left);
                if(top->right != NULL) q.push(top->right);
            }
            lvl++;
        }
        return lvl;
    }
};