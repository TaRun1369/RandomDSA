class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lb = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        
        if(lb != nums.size() && nums[lb] == target){
            return lb;
        }
        else return lb;

    }
};