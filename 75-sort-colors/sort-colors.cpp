class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        for(auto it : nums){
            if(it == 0) zero++;
            if(it == 1) one++;
        }
        cout<<zero<<" "<<one<<endl;
        for(int i= 0;i<zero;i++){
            nums[i] = 0;
        }
        for(int j = zero;j<one + zero;j++){
            // cout<<"yaha"<<endl;
            nums[j] = 1;
        }
        for(int k = one + zero;k<nums.size();k++){
            nums[k] = 2;
        }

    }
};