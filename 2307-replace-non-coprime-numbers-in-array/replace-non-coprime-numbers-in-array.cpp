class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st; // using vector as stack
        for (int x : nums) {
            st.push_back(x);
            while (st.size() > 1) {
                int a = st.back();
                int b = st[st.size()-2];
                int g = gcd(a, b);
                if (g == 1) break; // coprime, stop merging
                st.pop_back();
                st.pop_back();
                long long l = (1LL * a / g) * b; // lcm with overflow safe
                st.push_back((int)l);
            }
        }
        return st;
    }
};
