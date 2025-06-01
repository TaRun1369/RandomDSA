class Solution {
public:
    long long nc2(int n){
        if(n < 2) return 0;

        return n *1LL* (n-1)*1LL /2;
    }
    long long distributeCandies(int n, int limit) {
        // long long ans = 0;

        // for(int i = 0;i<=min(n,limit);i++){
        //     int rem = n - i;
        //     if(rem > 2*limit) continue;
        //     int low = max(0,rem - limit);
        //     int up = min(limit,rem);
        //     ans += (up - low + 1);
        // }
        // return ans;
        int l = limit;
        long long ans = nc2(n + 2) - 3LL * nc2(n - (l + 1) + 2) + 3LL*nc2(n - 2*(l + 1) + 2) - nc2(n - 3*(l + 1) + 2);
        return ans;


    }
};