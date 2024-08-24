// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int ans= 0;
//         int n = s.size();
//         vector<int> prevcurr(n,0);
//         stack <pair<char,int>> st;
//         // int stopen  = 0;// ( wala
//         // int stclose = 0; // ) wala
//         int currans = 0;
//         int maxi = 0;
//         for(int i = 0;i<n;i++){
//             char it = s[i];
//             if(it == '(') {
//                 st.push({it,i});
//                 // stopen++;
//             }
//             else {
//                 if(st.size() != 0){
//                     auto t = st.top();
//                     st.pop();
//                     int ans = prevcurr[t.second] + 2;
//                     if(i + 1 < n)
//                     prevcurr[i+1] = ans;
//                     maxi = max(maxi,ans);
//                     cout<<i<<" "<<maxi<<endl;
//                 }
//                 else{
//                     // stopen = 0;
//                     // currans = 0;
//                 }
//             }
//         } 
//         return maxi;
//     }
// };
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int n = s.size();
        vector<int> prevcurr(n, 0);
        stack<int> st; // Store indices of '('

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            char it = s[i];
            if (it == '(') {
                st.push(i);
            } else {
                if (!st.empty()) {
                    int t = st.top();
                    st.pop();
                    int length = i - t + 1; // Basic valid length
                    if (t > 0) {
                        length += prevcurr[t - 1]; // Add previous valid length if exists
                    }
                    prevcurr[i] = length;
                    maxi = max(maxi, length);
                }
            }
        } 
        return maxi;
    }
};
