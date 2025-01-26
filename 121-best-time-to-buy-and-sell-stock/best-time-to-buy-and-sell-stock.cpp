class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mini = INT_MAX;
        int ans = 0;
        for(auto it : prices){
            mini =min(it,mini);
            ans = max(ans,it - mini);
        }
        return ans;
    }
};