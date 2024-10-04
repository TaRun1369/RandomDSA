class Solution {
public:
    long long maximumTotalSum(vector<int>& m) {
        sort(m.begin(),m.end());

        for(int i = 0;i<m.size();i++){
            if(m[i] < i + 1) return -1;
        }
        int n = m.size();
        long long ans = 0;
        int prev = INT_MAX;
        for(int i = n - 1;i>=0;i--){
            int x = min(prev - 1,m[i]);
            ans += x;
            cout<<i<<"  "<<ans<<endl;
            prev = x;
        }
        return ans;
    }
};