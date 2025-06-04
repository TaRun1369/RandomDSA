class Solution {
public:
    void recur(vector<int>& c, int target,int ind,set<vector<int>> &ans,vector<int> &temp){
        if(target < 0 ) return;
        if(target == 0){
            ans.insert(temp);
        }
        if( ind >= c.size())return;
        temp.push_back(c[ind]);
        recur(c,target - c[ind], ind,ans,temp);
        temp.pop_back();

        recur(c,target,ind + 1,ans,temp);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> temp;
        recur(candidates,target,0,ans,temp);
        vector<vector<int>> anss(ans.begin(),ans.end());
        return anss;
    }
};