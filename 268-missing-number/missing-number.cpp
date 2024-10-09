class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum = accumulate(nums.begin(),nums.end(),0ll);
        long long tot = nums.size() * (nums.size() + 1)/2;
        return tot - sum;
    }
};