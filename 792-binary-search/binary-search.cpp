class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ind = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        if(ind != nums.size() && nums[ind] == target) return ind;

        return -1;
    }
};