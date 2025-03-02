class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> mp;
        for(auto it : nums1){
            int id = it[0],val = it[1];
            mp[id] += val;
        }
        for(auto it : nums2){
            int id = it[0],val = it[1];
            mp[id] += val;
        }

        vector<vector<int>> ans;

        for(auto it : mp){
            ans.push_back({it.first,it.second});
        }
        return ans;

    }
};