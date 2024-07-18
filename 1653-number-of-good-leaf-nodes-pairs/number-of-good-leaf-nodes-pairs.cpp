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
int ans = 0;

    int countPairs(TreeNode* root, int distance) {
    dfs(root,distance);
    return ans;
    }

    vector<int> dfs(TreeNode* root,int dist){
        if(root == NULL) return  {};
        vector<int> temp = {};

        auto lef = dfs(root->left,dist);
        auto rig = dfs(root->right,dist);

        if(lef.size() == 0 && rig.size() == 0){
            temp.push_back(1);
            //leaf node
            return temp;
        }

        for(int i = 0;i<lef.size();i++){
            for(int j = 0;j<rig.size();j++){
                if(lef[i] + rig[j] <= dist){
                    ans++;
                }
            }
        }

        for(int i = 0;i<lef.size();i++){
            lef[i]++;
            temp.push_back(lef[i]);
        }
        for(int i = 0;i<rig.size();i++){
            rig[i]++;
            temp.push_back(rig[i]);
        }

        return temp;


    }
};