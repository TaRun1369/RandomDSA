class Solution {
public:
    vector<int> ans;
    vector<bool> used;
    int n;
    
    bool dfs(int index) {
        if (index == ans.size()) return true; 
        if (ans[index] != 0) return dfs(index + 1); 
        
        for (int num = n; num >= 1; --num) { 
            if (used[num]) continue;
            
            if (num == 1) { 
                ans[index] = 1;
                used[num] = true;
                if (dfs(index + 1)) return true;
                ans[index] = 0;
                used[num] = false;
            } else {
                int secondIndex = index + num;
                if (secondIndex < ans.size() && ans[secondIndex] == 0) { 
                    ans[index] = ans[secondIndex] = num;
                    used[num] = true;
                    if (dfs(index + 1)) return true;
                    ans[index] = ans[secondIndex] = 0;
                    used[num] = false;
                }
            }
        }
        return false;
    }
    
    vector<int> constructDistancedSequence(int _n) {
        n = _n;
        ans.resize(2 * n - 1, 0);
        used.resize(n + 1, false);
        dfs(0);
        return ans;
    }
};