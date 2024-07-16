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
    string start,end;
    void inorder(TreeNode* root,string &one,int value){
        if(root == NULL) return;
        if(root->val == value){
            start = one;
            return;
        }

        one += "L";
        inorder(root->left,one,value);
        one.pop_back();
        one += "R";
        inorder(root->right,one,value);
        one.pop_back();
    }
    void inorder1(TreeNode* root,string &two,int value){
        if(root == NULL) return;
        if(root->val == value){
            end = two;
            return;
        }

        two += "L";
        inorder1(root->left,two,value);
        two.pop_back();
        two += "R";
        inorder1(root->right,two,value);
        two.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // string ans = "";
        string one = "";
        string two = "";
        inorder(root,one,startValue);
        inorder1(root,two,destValue);
        // start aur end bann gaye now two pointers 
        int i = 0, j =0;
        while(i < start.size() && j < end.size()){
            if(start[i] == end[j]){
                i++;
                j++;
            }
            else break;
        }
        string sub = "";
        while(i < start.size()){
            sub += "U";
            i++;
        }
        for(;j<end.size();j++){
            sub += end[j];
        }
        return sub;
    }
};