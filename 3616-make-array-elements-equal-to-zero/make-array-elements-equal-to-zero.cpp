class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> pref(n,0),suff(n,0);
        pref[0] = nums[0];
        for(int i = 1;i<n;i++){
            pref[i] = pref[i - 1] + nums[i];
        }
        suff[n - 1] = nums[n-1];
        for(int i = n - 2;i >=0;i--){
            suff[i] = suff[i + 1] + nums[i];
        }
        for(int i = 0;i<n;i++){
            if(nums[i] == 0 ){
                if(pref[i] == suff[i])
                ans += 2;
                else if(abs(pref[i] - suff[i]) == 1) ans +=1;
            }
            
        }
        return ans;
    }
};