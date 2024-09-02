class Solution {
public:
    int chalkReplacer(vector<int>& c, int k) {
        long long sum = accumulate(c.begin(),c.end(),0ll);
        k %= sum;

        for(int i = 0;i<c.size();i++){
            if(c[i] > k) return i;
            else k -= c[i];
        }

        return c.size()-1;
    }
};