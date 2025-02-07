class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        // -4 -1 1 2
        int mini = INT_MAX;
        int ans;
        for(int i = 0;i<n - 2;i++){
            int j = i + 1;
            int k = n - 1;
            // int sum = nums[i] + nums[j] + nums[k];
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(target - sum);
                if(diff < mini){
                    ans = sum;
                    mini = diff;
                }
                if(sum < target){
                    j++;
                }
                else{
                    k--;
                }

            }

        }
        return ans;

    }
};