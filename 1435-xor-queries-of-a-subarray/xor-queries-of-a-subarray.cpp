class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefxor(n);
        prefxor[0] = arr[0];
        int pre = arr[0];
        for(int i = 1;i<arr.size();i++){
            pre ^= arr[i];
            prefxor[i] = pre;
        }
        vector<int> ans;
        for(auto it : queries){
            if(it[0] - 1 >= 0)
            ans.push_back(prefxor[it[1]] ^ prefxor[it[0] - 1]);
            else{
                ans.push_back(prefxor[it[1]]);
            }

        }
        return ans;
    }
};