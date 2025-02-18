class Solution {
public:
    int kadane(vector<int> &nums){
        int n = nums.size();
        int sum = 0;
        int maxi = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
            if(sum < 0) sum = 0;
            maxi = max(maxi,sum);
        }
        return maxi;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = kadane(nums);

        for(auto &it : nums){
            it*=(-1);
        }
        ans = max(ans,kadane(nums));
        return ans;
    }
};