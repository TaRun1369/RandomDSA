class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int n = s.size();
        string ans = "";
        while(i < n){
            while(s[i] == ' '){i++;continue;}

            string a = "";
            while(i < n && s[i] != ' '){
                a+= s[i];
                i++;
            }

            ans = a + " " + ans;
        }
        int st= 0,en = ans.size() - 1;
        while(ans[st] == ' '){
            st++;
        }
        while(ans[en] == ' '){
            en--;
        }
        string anss = ans.substr(st,en - st + 1);
        return anss;
    }
};