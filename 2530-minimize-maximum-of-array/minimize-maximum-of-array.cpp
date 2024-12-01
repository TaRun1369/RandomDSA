// class Solution {
// public:
//     bool check(vector<long long> nums,int k){
//         if(nums[0] > k) return false;
//         for(int i = 1;i<nums.size();i++){
//             if(nums[i] > k){
//                 int diff = nums[i] - k;
//                 nums[i] = k;
//                 nums[i - 1] += diff;
//                 if(nums[i - 1] > k) return false;
//             }
//         }
//         // int n = nums.size();
//         // long long curr = nums[n-1] , prev = nums[n - 2];
//         // for(int i = n - 1;i>0;i--){
//         //     if(curr > k){
//         //         long long diff = nums[i] - k;
//         //         prev += diff;
//         //         curr = prev;
//         //     }
//         //     else{
//         //         curr = nums[i - 1];
//         //         if(i -2 >= 0)
//         //         prev = nums[i - 2];
//         //         else break;
//         //     }
//         // }
//         return nums[0] <= k;
//     }
//     int minimizeArrayValue(vector<int>& nums) {
//         // BS on ans

//         int low = *min_element(nums.begin(),nums.end());
//         int high = *max_element(nums.begin(),nums.end());

//         // cout<<low<<high<<endl;
//         long long ans = high;

//         while(low <= high){
//             long long mid = low + (high - low)/2;
//             // cout<<mid<<" - ";
            
            
//             if(check(idlt,mid)){
//                 // cout<<"check"<<endl;
//                 ans = min(mid,ans);
//                 high = mid - 1;
//             }
//             else{
//                 low = mid + 1;
//             }
//         }
//         return ans;
//     }
// };
// // class Solution {
// // public:
// //     int minimizeArrayValue(vector<int>& nums) {
// //         long long totalSum = 0;
// //         long long result = 0;
        
// //         for (int i = 0; i < nums.size(); i++) {
// //             totalSum += nums[i];
            
// //             result = max(result, (totalSum + i) / (i + 1));
// //         }
        
// //         return result;
// //     }
// // };


class Solution {
public:
    bool check(vector<long long> nums,int k){
        if(nums[0] > k) return false;
        // for(int i = 1;i<nums.size();i++){
        //     if(nums[i] > k){
        //         int diff = nums[i] - k;
        //         nums[i] = k;
        //         nums[i - 1] += diff;
        //         if(nums[i - 1] > k) return false;
        //     }
        // }
        int n = nums.size();
        for(int i = n - 1;i>0;i--){
            if(nums[i] > k){
                long long diff = nums[i] - k;
                nums[i - 1] += diff;
                nums[i] = k;
            }
        }
        return nums[0] <= k;
    }
    int minimizeArrayValue(vector<int>& nums) {
        // BS on ans

        int low = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());
        vector<long long> idlt;
        for(auto it : nums) idlt.push_back(it);
        // cout<<low<<high<<endl;
        long long ans = high;
        while(low <= high){
            long long mid = low + (high - low)/2;
            // cout<<mid<<" - ";
            if(check(idlt,mid)){
                // cout<<"check"<<endl;
                ans = min(mid,ans);
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};