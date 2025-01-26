class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0;i<n;i++){
            // cout<<nums[i]<<endl;
            if(mp.find(nums[i]) != mp.end() ){
                cout<<i<<mp[nums[i]]<<endl;
                if(i - mp[nums[i]] <= k)
                    return true;
                
            }
            mp[nums[i]] = i;
        
        }
        return false;
    }
};