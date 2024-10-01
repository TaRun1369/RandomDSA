class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int, int> mp;
        
        for (auto it : arr) {
            int remainder = ((it % k) + k) % k; 
            mp[remainder]++;
        }

        for (auto it : mp) {
            int rem = it.first;
            if (rem == 0) {
                if (mp[rem] % 2 != 0) return false;
            }
            else {
                if (mp[rem] != mp[k - rem]) return false;
            }
        }

        return true;
    }
};
