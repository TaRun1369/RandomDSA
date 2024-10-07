class Solution {
public:
    int calc(vector<int> &ind,int k){
        int len = 0;
        int ans = 0;

        int start = 0,end = 0;
        while(end < ind.size()){
            if(end == 0)len++;
            else{
            int rem = ind[end] - ind[end - 1] - 1;
            k -= rem;
            while(k < 0){
                k += (ind[start + 1] - ind[start] - 1);
                len--;
                start++;
            }
            len++;
            }
            ans = max (ans,len);
            end++;
        }
        return ans;
    }
    int longestEqualSubarray(vector<int>& nums, int k) {
        map<int,vector<int>> mp;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        int res = 0;
        for(auto it : mp) res = max(res,calc(it.second,k));

        return res;
    }
};