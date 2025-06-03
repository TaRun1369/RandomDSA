class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& t) {
        sort(t.begin(),t.end());
        int n = t.size();
        vector<vector<int>> ans;
        for(int i = 1;i<n;i++){
            if(t[i][0] >= t[i-1][0] && t[i-1][1] >= t[i][0]){
                t[i][0] = min(t[i][0],t[i-1][0]);
                t[i][1] = max(t[i][1],t[i-1][1]);
            }
            else{
                ans.push_back(t[i-1]);
            }
        }
        ans.push_back(t[n-1]);
        return ans;
    }
};