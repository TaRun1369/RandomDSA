class Solution {
public:
    void recur(vector<int> &hash, set<string> &st, string &s) {
        for (int i = 0; i < 26; i++) {
            if (hash[i] > 0) {
                s += (i + 'A');
                st.insert(s);
                hash[i]--;
                recur(hash, st, s);
                hash[i]++;
                s.pop_back();
            }
        }
    }

    int numTilePossibilities(string tiles) {
        vector<int> hash(26, 0);
        for (char it : tiles) {
            hash[it - 'A']++;
        }
        set<string> st;
        string s = "";
        recur(hash, st, s);
        return st.size();
    }
};
