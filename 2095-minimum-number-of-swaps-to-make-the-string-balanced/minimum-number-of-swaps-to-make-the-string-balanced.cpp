class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;

        for(auto it : s){
            if(it == ']'){
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }
            }
            else{
                st.push(it);
            }
        }
        return (st.size() + 1)/2;
    }
};