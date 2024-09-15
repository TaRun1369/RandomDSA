class Solution {
public:
    int findTheLongestSubstring(string s) {
        map<int, int> mp;
        int val = 0;
        int n = s.size();
        int ans = 0;
        mp[0] = -1; 

        for (int j = 0; j < n; j++) {
            char it = s[j];
            
            if (it == 'a') {
                val ^= (1 << 0); 
            } else if (it == 'e') {
                val ^= (1 << 1);  
            } else if (it == 'i') {
                val ^= (1 << 2);  
            } else if (it == 'o') {
                val ^= (1 << 3);  
            } else if (it == 'u') {
                val ^= (1 << 4); 
            }
            
            if (mp.find(val) != mp.end()) {
                ans = max(ans, j - mp[val]);  
            } else {
                mp[val] = j; 
            }
        }
        return ans;
    }
};
