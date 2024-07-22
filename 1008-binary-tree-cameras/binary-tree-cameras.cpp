
class Solution {
public:
    map<pair<TreeNode*, pair<bool, bool>>, int> dp;

    int solve(TreeNode* node, bool currCam, bool parCam) {
        // if node is NULL
        if (node == NULL) {
            if (currCam) return 1e9;
            else return 0;
        }
        // leaf node
        if (node->right == NULL && node->left == NULL) {
            if (currCam) {
                return 1;
            } else {
                if (parCam) return 0;
                else return 1e9;
            }
        }

        if (dp.find({node, {currCam, parCam}}) != dp.end()) {
            return dp[{node, {currCam, parCam}}];
        }
        // rest 4 cases for each node 
        if (currCam) {
            return dp[{node, {currCam, parCam}}] = 1 + (min(solve(node->left, 0, currCam), solve(node->left, 1, currCam))  + min(solve(node->right, 0, currCam), solve(node->right, 1, currCam)));
        } else {
            if (parCam) {
                return dp[{node, {currCam, parCam}}] = (min(solve(node->left, 0, currCam), solve(node->left, 1, currCam))  + min(solve(node->right, 0, currCam), solve(node->right, 1, currCam)));
            } else {
                int op1 = solve(node->left, 1, 0) + min(solve(node->right, 0, currCam), solve(node->right, 1, currCam));
                int op2 = solve(node->right, 1, 0) + min(solve(node->left, 0, currCam), solve(node->left, 1, currCam));
                return dp[{node, {currCam, parCam}}] = min(op1, op2);
            }
        }
    }

    int minCameraCover(TreeNode* root) {
        return min(solve(root, 0, 0), solve(root, 1, 0));
    }
};
