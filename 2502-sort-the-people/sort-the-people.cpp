class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        vector<pair<int ,string>> HN;
        int n= names.size();
        for(int i = 0;i<n;i++){
            HN.push_back({heights[i],names[i]});
        }

        sort(HN.rbegin(),HN.rend());

        for(auto it : HN){
            ans.push_back(it.second);
        }
        return ans;
    }
};