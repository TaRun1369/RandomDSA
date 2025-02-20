class Solution {
public:
    int n_;
    string ans = "";
    bool recur(string &s,vector<string> &nums,set<string> &st){
        if(s.size() > n_) return false;
        if(s.size() == n_ && st.find(s) == st.end()){ ans = s;return true;}

        s += '0';
        if(recur(s,nums,st)) return true;
        s.pop_back();
        s+= '1';
        if(recur(s,nums,st)) return true;
        s.pop_back();

        return false;
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        n_ = n;
        set<string> st(nums.begin(),nums.end());
        string s = "";
        recur(s,nums,st);
        return ans;
    }
};