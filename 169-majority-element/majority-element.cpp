class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int banda = INT_MIN;
        int kitne = 0;

        for(int i = 0;i<nums.size();i++){
            if(nums[i] == banda){
                kitne++;
            }
            else if(banda != INT_MIN){
                kitne--;
            }
            if(kitne == 0){
                banda = nums[i];
                kitne = 1;
            }

        }
        return banda;
    }
};