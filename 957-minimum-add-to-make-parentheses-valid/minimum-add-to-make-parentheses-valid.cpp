class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;

        for(auto it : s){
            if(it == ')') {
                if(!st.empty() && st.top() == '(') st.pop();
                else
                st.push(it);
            }
            else{
                st.push(it);
            }
        }
        return int(st.size());
    }
};