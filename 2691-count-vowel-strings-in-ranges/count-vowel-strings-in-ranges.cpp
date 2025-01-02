class Solution {
public:
    bool isvowel(char cc){
        if(cc == 'a' || cc == 'e' || cc == 'i'|| cc == 'o'||cc == 'u') return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // 1 1 2 3 4
        // 1 2 3 4 5
        int n = words.size();
        vector<int> c (words.size() + 1,0);
        c[0] = 0;
        for(int i = 0;i<n;i++){
            int f = 0;
            if(isvowel(words[i][0]) && isvowel(words[i][words[i].size() - 1])) f = 1;
            c[i + 1] = c[i] + f;
        }
        vector<int> ans;
        for(auto it : queries){
            ans.push_back(c[it[1] + 1] - c[it[0]]);
        }
        return ans;
    }
};