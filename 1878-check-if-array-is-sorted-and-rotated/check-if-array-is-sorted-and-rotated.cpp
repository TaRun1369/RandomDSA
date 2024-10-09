class Solution {
public:
    bool check(vector<int>& nums) {
        // 1 2 2 3 3 4 4
        // 2 3 3 4 4 1 2
        
        // 1 2 2
        // 2 1 2
        
        vector<int> fir,sec;
        sec.push_back(nums[0]);
        int f = 0;
        int n = nums.size();
        for(int i = 1;i<n;i++){
            if(nums[i - 1] > nums[i]){
                f = 1;
            }

            if(f == 1){
                fir.push_back(nums[i]);
            }
            else {
                sec.push_back(nums[i]);
            }
        }

        for(auto it : sec){
            fir.push_back(it);
        }

        for(int i = 1;i<n;i++){
            if(fir[i - 1] > fir[i]) return false;
        }

        return true;
    }
};