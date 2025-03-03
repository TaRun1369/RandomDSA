class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> chote, bade;
        int count = 0;
        for(auto it : nums){
            if(it < pivot){
                chote.push_back(it);
            }
            else if(it == pivot ){
                count++;
            }
            else{
                bade.push_back(it);
            }
        }
        for(int i = 0;i<count;i++){
            chote.push_back(pivot);
        }
        for(auto it : bade){
            chote.push_back(it);
        }
        return chote;

    }
};