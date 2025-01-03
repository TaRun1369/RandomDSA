class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long tot = accumulate(nums.begin(),nums.end(),0ll);
        // t;
        int n = nums.size();
        long long sum = 0;
        int ans = 0;
        for(int i = 0;i<n-1;i++){
            sum += nums[i];
            tot -= nums[i];
            if(sum >= tot) ans++;
        }
        return ans;
    }
};