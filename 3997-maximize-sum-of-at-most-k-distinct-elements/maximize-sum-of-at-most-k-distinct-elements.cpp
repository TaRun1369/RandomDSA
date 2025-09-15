class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.rbegin(),nums.rend());
        vector<int> ans;
        int prev = 0;
        for(auto it : nums){
            if(k == 0) return ans;
            if(it != prev){ ans.push_back(it);k--;}
            prev = it;
        }
        return ans;
    }
};