class Solution {
public:
    vector<string> happyStrings;
    
    void generateHappyStrings(int n, string &s) {
        if (s.size() == n) {
            happyStrings.push_back(s);
            return;
        }
        
        for (char ch : {'a', 'b', 'c'}) {
            if (s.empty() || s.back() != ch) { 
                s.push_back(ch);
                generateHappyStrings(n, s);
                s.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        string s = "";
        generateHappyStrings(n, s);
        
        if (k > happyStrings.size()) return ""; 
        return happyStrings[k - 1]; 
    }
};
