class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp;
        int maxi = 0,ans = 0;
        for(auto it : nums){
            mp[it]++;
             maxi = max(maxi,mp[it]);
        }
        cout<<"maxi - "<<maxi<<endl;

        for(auto it : mp){
            if(it.second == maxi) {
                ans += (maxi);
            }
        }

        return ans;
    }
};