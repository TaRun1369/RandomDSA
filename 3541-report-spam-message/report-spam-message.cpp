class Solution {
public:
    bool reportSpam(vector<string>& m, vector<string>& bannedWords) {
        set<string> s ( bannedWords.begin(),bannedWords.end());
        int c = 0 ;
        for(auto it : m){
            if(s.find(it) != s.end()){
                c++;
            }
        }

        return c >= 2;
    }
};