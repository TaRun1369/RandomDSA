class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            mini=min(nums[i],mini);
        }
        if(k>mini)return -1;
        int cnt=0;
        set<int>st(nums.begin(),nums.end());
        return k==mini?st.size()-1:st.size();
    }
};