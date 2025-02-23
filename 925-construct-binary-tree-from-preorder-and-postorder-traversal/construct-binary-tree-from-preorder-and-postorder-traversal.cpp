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
    unordered_map<int,int> mp;
    TreeNode* recur(int preSt,int preEn,int postSt,vector<int>& pre, vector<int>& post){
        if(preSt > preEn) return NULL;

        TreeNode* root = new TreeNode(pre[preSt]);
        if(preSt == preEn) return root;
        int nextNode = pre[preSt + 1];
        int j = postSt;
        // while(post[j] != nextNode){
        //     j++;
        // }
        j = mp[nextNode];
        int num = j - postSt + 1;

        root->left = recur(preSt + 1,preSt + num,postSt,pre,post);
        root->right = recur(preSt + num + 1,preEn,j + 1,pre,post);
        return root;
        
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        // PRE - ROOT LEFT RIGHT
        // POST - LEFT RIGHT ROOT
        int n = pre.size();
        for(int i = 0;i<post.size();i++) mp[post[i]] = i;
        return recur(0,n-1,0,pre,post);
    }
};