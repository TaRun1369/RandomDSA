class Solution {
public:
    int minOperations(vector<int>& nums) {
        int prev = nums[0];
        int ans = 0;
        for(int i = 1;i<nums.size();i++){
            if(nums[i] > prev){
                prev = nums[i];
                continue;
            }
            else{
                ans += (prev + 1 - nums[i]);
                nums[i] = prev + 1;
                prev++;
            }
        }
        return ans;
    }
};