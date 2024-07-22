class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; // for indexes of pse
        int n = heights.size();
        int maxans = 0;
        for(int i = 0;i<n;i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int top = st.top();
                st.pop();
                int pse;
                if(st.empty()) pse = -1;
                else pse = st.top();
                maxans = max(maxans , heights[top] * (i - pse - 1));
                cout<<maxans<<"     "<<top<<endl;
            }
            st.push(i);
        }

        while(!st.empty()){
            int t = st.top();
            st.pop();
            int pse;
            if(st.empty()) pse = -1;
            else pse = st.top(); 
            maxans = max(maxans,heights[t] * (n - pse - 1));
            cout<<maxans<<"     "<<t<<endl;

        }

        return maxans;
    }
};