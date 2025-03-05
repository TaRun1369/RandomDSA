class Solution {
public:
    long long coloredCells(int n) {
        // 1 
        // 1 + 4 * 1   or  1 + 3 + 1
        // 1 + 4 * 2 or 1 + 3 + 5 + 3 + 1
        // 1 + 4 * 6    or 1 + 3 + 5 + 7 + 5 + 3 + 1
        // 1 + 4 * 10         or 
        // return 0;
        return 1 + (1ll*4*1ll * ((n)*1ll*(n-1)*1ll/2));
    }
};