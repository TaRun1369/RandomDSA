class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int gmax = INT_MIN,gmin = INT_MAX;
        int n = arrays.size();
        for(auto it : arrays[0]){
            gmax = max(gmax,it);
            gmin = min(gmin,it);
        }
        int ans = INT_MIN;
        for(int i = 1;i<n;i++){
            int lmin = INT_MAX,lmax = INT_MIN;
            for(auto it : arrays[i]){
                lmin = min(lmin,it);
                lmax = max(lmax,it);
            }
            int diff1 = abs(lmin - gmax);
            int diff2 = abs(lmax - gmin);
            ans = max(ans,max(diff1,diff2));
            gmax = max(gmax,lmax);
            gmin = min(gmin,lmin);


        }
    return ans;
    }

};