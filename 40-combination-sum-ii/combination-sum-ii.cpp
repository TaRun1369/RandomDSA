class Solution {
public:
    vector<vector<int>> ans;
    void recur(int ind,vector<int> &c,int t,vector<int> &temp){
        if(t == 0){
            ans.push_back(temp);
            return;
        }
        for(int i = ind;i<c.size();i++){
            if(i > ind && c[i] == c[i-1]) continue;
            if(c[i] > t) continue;
            temp.push_back(c[i]);
            recur(i+1,c,t - c[i],temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(),c.end());
        vector<int> temp;
        recur(0,c,t,temp);
        return ans;
    }
};