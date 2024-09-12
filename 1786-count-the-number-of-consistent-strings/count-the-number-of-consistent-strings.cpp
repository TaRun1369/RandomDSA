class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> hash1(26,false);

        for(auto it : allowed){
            hash1[it - 'a'] = true;
        } 
        int ans = 0;

        for(auto it : words){
            int f = 1;
            for(auto iss : it){
                if(hash1[iss - 'a'] == 0) {
                    f = 0;
                    break;
                }
            }
            if(f == 1) ans++;
        }

        return ans;
    }
};