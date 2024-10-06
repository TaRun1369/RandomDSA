class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> hashS1(26,0),hashS2(26,0);
        for(auto &it : s1){
            hashS1[it - 'a']++;
        }
        int n = s1.size(),m = s2.size();
       if(n > m) return false;
       int i = 0,j = 0;

       while(j < m){
            hashS2[s2[j] - 'a']++;

            if(j - i + 1 > n){
                hashS2[s2[i] - 'a']--;
                i++;
            }

            if(hashS2 == hashS1) return true;

            j++;
       }
       return false;
    }
};