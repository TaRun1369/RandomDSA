class Solution {
public:
    int cal(vector<int>&nums,int mid){
        int i = 0;
        int j = mid;
        int n = nums.size();
        int ans = 0;
        while(j < n && i < mid){
            if(nums[i] * 2 <= nums[j]){
                cout<<nums[i]<<" badaa "<<nums[j]<<endl;
                ans+=2;
                i++;
                j++;

            }
            else{
                 cout<<nums[i]<<" "<<nums[j]<<endl;
                 j++;
                 }
        }
        return ans;
    }
    int maxNumOfMarkedIndices(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int n = nums.size();
       
       cout<<n<<endl;
       long long sum = accumulate(nums.begin(),nums.end(),0ll);
    //    sum /= n;
       for(auto it : nums){
        cout<<it<<" ";
       }
       cout<<endl;
    // int lower= lower_bound(nums.begin(),nums.end(),sum) - nums.begin();
       int mid = n/2;  
       return max(cal(nums,mid),cal(nums,mid + 1));
    }
};