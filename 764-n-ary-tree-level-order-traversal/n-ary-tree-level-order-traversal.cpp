/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;

        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            int siz = q.size();
            vector<int> level;
            for(int i = 0;i<siz;i++){
                Node* dt = q.front();
                q.pop();
                if(dt != NULL){
                level.push_back(dt->val);
                for(auto it : dt->children){
                    if(it != NULL)
                    q.push(it);
                }
                }
            }
            if(level.size() > 0)
            ans.push_back(level);
        }
        return ans;
    }
};