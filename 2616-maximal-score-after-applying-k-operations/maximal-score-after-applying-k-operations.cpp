class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(auto it : nums){
            pq.push(it);
        }
        long long ans = 0;
        while(k--){
            ans += pq.top();
            int curr = pq.top();
            pq.pop();
            // cout<<ceil(curr/3)<<endl;
            int rem = curr%3;
            curr/=3;
            if(rem > 0) curr++;
            pq.push(curr);
        }
        return ans;
    }
};