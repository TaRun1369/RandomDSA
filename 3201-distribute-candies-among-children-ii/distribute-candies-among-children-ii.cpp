class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;

        for(int i = 0;i<=min(n,limit);i++){
            int rem = n - i;
            if(rem > 2*limit) continue;
            int low = max(0,rem - limit);
            int up = min(limit,rem);
            ans += (up - low + 1);
        }
        return ans;
    }
};