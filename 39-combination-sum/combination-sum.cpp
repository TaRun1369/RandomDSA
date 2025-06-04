class Solution {
public:
    map<pair<int, int>, vector<vector<int>>> dp; // memoization map

    vector<vector<int>> recur(vector<int>& c, int target, int ind) {
        if (target == 0) return {{}};
        if (target < 0 || ind >= c.size()) return {};

        if (dp.find({ind, target}) != dp.end()) return dp[{ind, target}];

        vector<vector<int>> res;

        // Include current element
        vector<vector<int>> take = recur(c, target - c[ind], ind);
        for (auto comb : take) {
            comb.push_back(c[ind]);
            res.push_back(comb);
        }

        // Exclude current element
        vector<vector<int>> skip = recur(c, target, ind + 1);
        for (auto comb : skip) {
            res.push_back(comb);
        }

        return dp[{ind, target}] = res;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return recur(candidates, target, 0);
    }
};
