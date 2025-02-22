// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     TreeNode* recur(TreeNode* node,string &s,int i,int depth){
//         if(i >= s.size()) return NULL;
//         int value = 0;
        
//         while(s[i] >= 0 && s[i] <= 9){
//             value = value*10 + (s[i] - '0');
//             i++;
//         }
//         int d = 0;
//         while(s[i] == '-'){i++;d++;}
//         node = new TreeNode(value);
//         if(d > depth)
//         node->left = recur(node->left,s,i,d);
//         else
//         node->right = recur(node->left,s,i,d);
        
//         return node;
//     }
//     TreeNode* recoverFromPreorder(string s) {
//         if(s.size() == 0) return NULL;
//         TreeNode* root = NULL;
//         root = recur(root,s,0,0);
//         return root;
//     }
// };


class Solution {
public:
    int index = 0; 
    
    TreeNode* recur(string &s, int depth) {
        int numDashes = 0, value = 0;
        
        while (index < s.size() && s[index] == '-') {
            numDashes++;
            index++;
        }
        
        if (numDashes != depth) {
            index -= numDashes; 
            return nullptr;
        }

        while (index < s.size() && isdigit(s[index])) {
            value = value * 10 + (s[index] - '0');
            index++;
        }

        TreeNode* node = new TreeNode(value);
        
        node->left = recur(s, depth + 1);
        node->right = recur(s, depth + 1);
        
        return node;
    }

    TreeNode* recoverFromPreorder(string s) {
        return recur(s, 0);
    }
};
