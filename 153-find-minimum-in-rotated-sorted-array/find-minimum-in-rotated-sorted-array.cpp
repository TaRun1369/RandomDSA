class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = INT_MAX;
        int n = nums.size();
        int low = 0,high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            mini = min(mini,nums[mid]);

            if(nums[low] < nums[mid]){
                cout<<"yaha"<<endl;
                mini = min(mini,nums[low]);
                low = mid + 1;
            }
            else{
                mini = min(mini,nums[high]);
                cout<<"waha"<<endl;
                high = mid - 1;
            }
            
            
        }
        return mini;
    }
};