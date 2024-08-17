class Solution {
public:
    long long maxPoints(vector<vector<int>>& p) {
        int n = p.size();    
        int m = p[0].size(); 

        vector<long long> prev(m, 0);

        for (int i = 0; i < m; i++) {
            prev[i] = p[0][i];
        }

        for (int i = 1; i < n; i++) {
            vector<long long> left(m, 0), right(m, 0), curr(m, 0);

            left[0] = prev[0];
            for (int j = 1; j < m; j++) {
                left[j] = max(left[j - 1] - 1, prev[j]);
            }

            right[m - 1] = prev[m - 1];
            for (int j = m - 2; j >= 0; j--) {
                right[j] = max(right[j + 1] - 1, prev[j]);
            }

            for (int j = 0; j < m; j++) {
                curr[j] = p[i][j] + max(left[j], right[j]);
            }

            prev = curr;
        }

        return *max_element(prev.begin(), prev.end());
    }
};
