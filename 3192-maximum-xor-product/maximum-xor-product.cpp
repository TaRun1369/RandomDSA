class Solution {
public:
    const long long mod = (long long)(1e9 + 7);
    int maximumXorProduct(long long a, long long b, int n) {
        for(long long i = n - 1;i>= 0;i--){
            long long bit = (long long)(1) <<i;
            if((bit & a) == (bit & b)){
                a = a|bit;
                b = b|bit;
            }
            else{
                if(a > b) swap(a,b);
                a = a|bit;
                b = b & (~bit);
            }
        }
        return ((a%mod) * (b %mod))%mod;
    }
};