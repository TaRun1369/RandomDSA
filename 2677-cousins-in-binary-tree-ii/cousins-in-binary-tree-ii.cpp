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
    TreeNode* replaceValueInTree(TreeNode* root) {
        // level order with parent 

        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root,NULL});
        map<TreeNode* , int> mp;
        while(!q.empty()){
            int siz = q.size();
            long long sum = 0;
            vector<pair<TreeNode*,TreeNode*>> v;
            for(int i = 0;i<siz;i++){
                auto fron = q.front();                
                v.push_back(fron);
                q.pop();
                if(fron.second != NULL)
                mp[fron.second] += fron.first->val;
                if(fron.first->left){
                    q.push({fron.first->left,fron.first});
                }
                if(fron.first->right){
                    q.push({fron.first->right,fron.first});
                }
                sum += fron.first->val;
            }

            for(auto it : v){
                if(it.second != NULL)
                it.first->val = sum - mp[it.second];
                else{
                    it.first->val = 0;
                }
            }

        }
        return root;
    }
};