class Solution {
public:
    long long jyada(string &word,int k){
        long long ans = 0;
        unordered_set<char> v = {'a','e','i','o','u'};
        unordered_map<char,int> vowel_map;
        int start = 0,end = 0,num_cons = 0;
        int n = word.size();

        while(start < n){
            if(vowel_map.size() == 5 && num_cons >= k){
                ans += (n - end + 1);
                if(v.find(word[start]) == v.end()) {
                    num_cons--;
                }
                else{
                    vowel_map[word[start]]--;
                    if(vowel_map[word[start]] == 0){
                        vowel_map.erase(word[start]);
                    }
                }
                start++;
            }
            else{
                if(end == n) break;
                if(v.find(word[end]) == v.end()) {
                    num_cons++;
                }
                else{
                    vowel_map[word[end]]++;
                }
                end++;
            }
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        return jyada(word,k) - jyada(word,k + 1);

    }
};