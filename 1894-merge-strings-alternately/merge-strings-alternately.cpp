class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        string ans = "";
        int n = min(w1.size(),w2.size());
        int  i = 0;
        for(;i<n;i++){
            // if(i % 2 == 0)
            ans += w1[i];
            // else{
            ans += w2[i];
            // }
        }

        while(i < w1.size()){ans += w1[i];i++;}
        while(i < w2.size()) {ans += w2[i];i++;}
        return ans;
    }
};