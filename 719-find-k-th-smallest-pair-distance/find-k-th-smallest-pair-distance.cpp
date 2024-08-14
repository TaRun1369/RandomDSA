class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr(1e6+1, 0);

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int diff = abs(nums[i] - nums[j]);
                arr[diff]++;
            }
        }

        for(int i = 0; i < arr.size(); i++){
            if(k <= arr[i]) return i;

            k -= arr[i];
        }

        return 1e6;
    }
};