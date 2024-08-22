// class Solution {
// public:
//     int sn, pn;
    
//     bool recur(int si, int pi, string &s, string &p) {
//         if (si >= sn && pi >= pn) return true;
        
//         if (pi >= pn) return false;
        
//         if (p[pi] == '*') {
           
//             return recur(si, pi + 1, s, p) || (si < sn && recur(si + 1, pi, s, p));
//         }
        
//         if (si < sn && (p[pi] == '.' || p[pi] == s[si])) {
//             return recur(si + 1, pi + 1, s, p);
//         }
        
        
//         return false;
//     }
    
//     bool isMatch(string s, string p) {
//         sn = s.size();
//         pn = p.size();
//         return recur(0, 0, s, p);
//     }
// };

class Solution {
public:
    int sn, pn;
    
    bool recur(int si, int pi, string &s, string &p) {
        // Base case: both strings are fully matched
        if (pi == pn) return si == sn;

        // Check if the next pattern character is '*'
        bool has_star = (pi + 1 < pn && p[pi + 1] == '*');

        if (has_star) {
            // Skip the current pattern character and '*' (zero occurrences) or
            // Use the current pattern character to match the current string character
            return (recur(si, pi + 2, s, p)) ||
                   (si < sn && (p[pi] == '.' || p[pi] == s[si]) && recur(si + 1, pi, s, p));
        } else {
            // No '*' following: Direct match required for current characters
            if (si < sn && (p[pi] == '.' || p[pi] == s[si])) {
                return recur(si + 1, pi + 1, s, p);
            } else {
                return false;
            }
        }
    }
    
    bool isMatch(string s, string p) {
        sn = s.size();
        pn = p.size();
        return recur(0, 0, s, p);
    }
};
