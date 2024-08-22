class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while(s[i] == ' ')i++;
        int neg = 1;
        if (s[i] == '-' || s[i] == '+') {
            neg = (s[i] == '-') ? -1 : 1; 
            i++;
        }
        long long ans = 0;
        

        while(i < s.size() && isdigit(s[i])){
            ans *= 10;
            ans += (s[i] - '0');
            if(ans > INT_MAX) {  // 
                return (neg == 1) ? INT_MAX : INT_MIN;
            }
            i++;
        }
        
        return ans* (neg);

    }
};