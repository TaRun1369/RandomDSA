class Solution {
public:
    bool possible(int k,vector<int> p,int h){
        long long curr = 0;
        for(auto it : p){
            curr += (it/k);
            if(it%k > 0) curr++;
        }
        return curr <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1,high = *max_element(piles.begin(),piles.end());
        long long ans = INT_MAX;
        while(low <= high){
            long long mid = (low + high )/2;
            if(possible(mid,piles,h)){
                ans = min(ans, mid);
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};