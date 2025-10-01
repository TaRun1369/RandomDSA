class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while(numBottles >= numExchange){
            int v = numBottles/numExchange;
            int r = numBottles%numExchange;

            ans += v;
            numBottles = v + r;
        }
        return ans;
    }
};