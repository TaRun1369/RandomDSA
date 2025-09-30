class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> temp;
        while(nums.size() != 1){
            int n = nums.size();
            temp.resize(n - 1);
            for(int i = 0;i<n-1;i++){
                temp[i] = (nums[i] + nums[i + 1])%10;
            }
            nums = temp;

        }

        return nums[0];
    }
};