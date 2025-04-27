class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        // int side = nums[0];
        int count = 0;
        for(int i = 1;i<n-1;i++){
            // if(i - 2 >= 0) side -= nums[i-2];
            int side = nums[i + 1] + nums[i - 1];
            // cout<<i<<" "<<side<<endl;
            if(nums[i] == (side * 2)) count++;
        }
        return count;
    }
};