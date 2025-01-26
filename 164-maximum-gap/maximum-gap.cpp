class Solution {
public:
    int maximumGap(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        int prev = -1,ans = INT_MIN;
        for(auto it : s){
            if(it == *s.begin()) {prev = it;continue;}
            ans = max(ans,it - prev);
            prev = it;
        }
        return ans == INT_MIN ?0 :ans;
    }
};