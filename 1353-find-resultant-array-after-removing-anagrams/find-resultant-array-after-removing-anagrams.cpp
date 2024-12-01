class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int i = 0, j = 1;
        int n = words.size();
        vector<int> ph(26,0);
        for(auto it : words[0]){
            ph[it - 'a']++;
        }
        vector<string> ans;
        ans.push_back(words[0]);
        for(;j < n;j++){
            vector<int> ch(26,0);
            for(auto it : words[j]){
                ch[it - 'a']++;
            }
            if(ch != ph){
                ans.push_back(words[j]);
                ph.clear();
                ph = ch;
                i = j;
            }
        }
        return ans;
    }
};