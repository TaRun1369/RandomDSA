class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1,-1};
        int n = nums.size();
        int low = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        if(low == n ||nums[low] != target) return {-1,-1};

        int i = low,j = low;
        while(i > 0 && nums[i - 1] == target){
            i--;
        } 
        while(j +1 < n && nums[j + 1] == target){
            j++;
        }

        return {i,j};
    }
};