class Solution {
public:
    bool check(vector<int>& nums) {
        // 1 2 2 3 3 4 4
        // 2 3 3 4 4 1 2
        
        // 1 2 2
        // 2 1 2
        
        int n = nums.size();
        int coun = 0;
        for (int i = 1;i<n;i++){
            if(nums[i - 1] > nums[i])coun++;

           

        }
         if(nums[n-1] >nums[0]) coun++;
                    return coun <= 1;

    }
};