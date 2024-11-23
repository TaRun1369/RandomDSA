class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i = 0;
        string temp = "";
        while(i < s.size()){
            if(s[i] == ' ') {
                i++;
                if(temp != ""){
                    temp = " " + temp;
                    ans = temp + ans;
                    
                }
                temp = "";
            }
            else{
                temp += s[i];
                i++;
            }   
        }
        if(temp != ""){
            ans = temp + ans;
        }
        i = 0;
        while(ans[i] == ' ')i++;
        string anss = ans.substr(i,ans.size() - i);
        return anss;
    }
};