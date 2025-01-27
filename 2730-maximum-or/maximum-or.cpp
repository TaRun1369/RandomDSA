class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n,0),suff(n,0);
        long long pre = nums[0],suf = nums[n-1];
        for(int i = 1;i<n;i++){
            pref[i] = pre;
            pre |= nums[i];
        }
        for(int i = n-2;i>=0;i--){
            suff[i] = suf;
            suf |= nums[i];
        }
        long long ans = 0;
        for(int i = 0;i<n;i++){
            // long long curr = (pref[i]*1LL) | (suff[i]*1LL) | ((nums[i] << k)*1LL);
            // ans = max(ans,curr);
            long long shifted = static_cast<long long>(nums[i]) << k;
            long long curr = (pref[i] * 1LL) | (suff[i] * 1LL) | shifted;
            ans = max(ans, curr);
        }

    return ans;
    }
};