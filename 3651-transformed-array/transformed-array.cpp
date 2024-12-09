class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n);
        for(int i=0;i<n;i++){
            if(nums[i]==0)result[i]=nums[i];
            else if(nums[i]>0){
              //  nums[i]=nums[(i+nums[i])%n];
                result[i]=nums[(i+nums[i])%n];
            }
            else{
                // nums[i]=nums[(i-nums[i])%n];
                result[i]=nums[((i+nums[i])%n + n)%n];
            }
        }
        return result;
    }
};