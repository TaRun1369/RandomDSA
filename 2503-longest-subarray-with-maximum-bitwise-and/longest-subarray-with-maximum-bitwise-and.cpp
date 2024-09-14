class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // int size = 1;
        // sort(nums.begin(),nums.end());
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end()) ; 
        int curr = 0; 
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == maxi) curr++;
            else curr = 0;

            ans = max(ans,curr);
        }
        return ans;
    }
};