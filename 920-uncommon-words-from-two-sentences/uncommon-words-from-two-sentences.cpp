class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int> mp1,mp2;
        int n = s1.size();
        int m = s2.size();
        vector<string> ans;
        for(int i = 0;i<n;){
            string a = "";
            while(i<n && s1[i] != ' '){
                a += s1[i];
                i++;
            }
            mp1[a]++;
            i++;
        }

        for(int i = 0;i<m;){
            string a = "";
            while(i<m && s2[i] != ' '){
                a += s2[i];
                i++;
            }
            // mp1[a]++;
            mp2[a]++;
            i++;
        }

        for(auto it : mp1){
            if(it.second < 2){
                if(mp2.find(it.first) == mp2.end()){
                    ans.push_back(it.first);
                }
            }
        }

        for(auto it : mp2){
            if(it.second < 2){
                if(mp1.find(it.first) == mp1.end()){
                    ans.push_back(it.first);
                }
            }
        }
        return ans;
    }
};