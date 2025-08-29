class Solution {
public:
    long long flowerGame(int n, int m) {
        long long on,en,om,em;
        on = (n + 1)/2;
        en = n/2;

        om = (m+1)/2;em = m/2;

        return (on*1LL*em*1LL) + (en*1LL*om*1LL);
    }
};