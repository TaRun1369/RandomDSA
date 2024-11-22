class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n =  nums.size();
        int bpt = n;
        for(int i = n - 2;i >= 0;i--){
            if(nums[i] < nums[i + 1]){
                cout<<"yaha"<<endl;
                bpt = i;
                break;
            }
        }
        cout<<" break pt - "<<bpt<<endl;

        if(bpt == n ){
            sort(nums.begin(),nums.end());
            return;
        }

        // swap with just greater banda 
        for(int i = n - 1;i > bpt;i--){
            if(nums[i] > nums[bpt]){
                swap(nums[i],nums[bpt]);
                break;
            }
        }

        sort(nums.begin() + bpt + 1,nums.end());

    }
};