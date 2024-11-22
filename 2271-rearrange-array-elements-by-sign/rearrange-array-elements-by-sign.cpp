class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos,neg;
        for(auto it : nums){
            if(it < 0) neg.push_back(it);
            else pos.push_back(it);
        }

        vector<int> ans;

        for(int i = 0;i<n/2;i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
        
    }
};