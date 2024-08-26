class Solution {
public:
    bool isnum(char c) {
        return c >= '0' && c <= '9';
    }

    int calculate(string s) {
        stack<int> st;
        int i = 0, n = s.size();
        char op = '+'; 
        while (i < n) {
            int num = 0;
            while (i < n && s[i] == ' ') i++;
            while (i < n && isnum(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            if (op == '*') {
                int top = st.top();
                st.pop();
                st.push(top * num);
            } else if (op == '/') {
                int top = st.top();
                st.pop();
                st.push(top / num);
            } else if (op == '-') {
                st.push(-num);
            } else { // For '+'
                st.push(num);
            }
            while (i < n && s[i] == ' ') i++;
            if (i < n) {
                op = s[i]; 
                i++;
            }
        }
        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};
