class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0,high = n - 1;

        while(low <= high){
            int mid = (low + high)/2;
            // cout<<low<<" "<<high<<" "<<mid<<endl;
            if( mid - 1 >= low && nums[mid] == nums[mid - 1]){
                // cout<<"yyy"<<endl;
                if((mid - low) % 2 == 0)
                high = mid;
                else {
                    low = mid + 1;
                }
            }
            else if(mid + 1 <= high && nums[mid] == nums[mid + 1]){
                // cout<<"iii"<<endl;
                if((mid - low) % 2 == 0)
                low = mid;
                else high = mid - 1;
            }
            else{

                return nums[mid];
            }

        }
        return -1;
    }
};