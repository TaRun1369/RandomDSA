class Solution {
public:
    int maxScore(string s) {
        // 1 0 1 1 0 1 1
// zero // 0 1 1 1 2 2 2
// one  // 4 4 3 2 2 1 1
        int one = 0;
        int n = s.size();
        for(int i = 1;i<n;i++){
            if(s[i] == '1') one++;
        }
        
        int ans = 0;
        int zero = 0;
        if(s[0] == '0')zero++;
        ans = max(ans,zero + one);
        for(int i = 1;i<n-1;i++){
            if(s[i] == '0')zero++;
            // cout<<zero<<" "<<one<<endl;
            ans = max(ans,zero + one);
            if(s[i] == '1') one--;
        }
        return ans;
    }
};