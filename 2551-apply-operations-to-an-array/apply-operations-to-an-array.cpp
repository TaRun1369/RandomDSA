class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0;i<n-1;i++){
            if(nums[i] == nums[i+1]){
                nums[i]*= 2;
                nums[i+1] = 0;
            }
        }
        for(auto it : nums){
            if(it != 0){
                ans.push_back(it);
            }
        }
        
        int count = nums.size() - ans.size();
        for(int i = 0;i<count;i++){
            ans.push_back(0);
        }
        return ans;
    }
};