class Solution {
public:
    int minCostToMoveChips(vector<int>& p) {
        int mini0 = 0,mini1 = 0;

        for(auto it : p){
            if(it % 2 == 0){
                mini0++;
            }
            else mini1++;
        }
        return min(mini0,mini1);
    }
};