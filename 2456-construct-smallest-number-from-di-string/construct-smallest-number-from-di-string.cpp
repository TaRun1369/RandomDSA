class Solution {
public:
    string ans = "999999999";
    void recur(string &s,string pattern,int ind,vector<int> &vis){
        if(s.size() == pattern.size() + 1){
            ans = min(ans,s);
            return;
        }

        if(pattern[ind] == 'I'){
            for(char i = (s[ind] + 1);i<='9';i++){
                if(!vis[i - '1']){
                s += i;
                vis[i - '1'] = 1;
                recur(s,pattern,ind + 1,vis);
                s.pop_back();
                vis[i - '1'] = 0;
                }
            }
        }
        else{
            for(char i = '1';i< s[ind];i++){
                if(!vis[i - '1']){
                s += i;
                vis[i - '1'] = 1;
                recur(s,pattern,ind + 1,vis);
                s.pop_back();
                vis[i - '1'] = 0;
                }
            }
        }
        
    }
    string smallestNumber(string pattern) {
           string temp = "";
           vector<int> vis(9,0);
           for(char i = '1';i<='9';i++){
                temp += i;
                vis[i - '1'] = 1;
                recur(temp,pattern,0,vis);
                temp = "";
                vis[i - '1'] = 0;
           } 
           return ans; 
    }
};