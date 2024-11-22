class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;

        for(auto it : nums){
            s.insert(it);
        }
        int ans = 0;
        for(auto it :s){
            if(s.find(it - 1)  == s.end()){
              // this is starting point of some sequence 

              int count = 1;
              while(s.find(it + 1) != s.end()){
                it++;
                count++;
              }  
              ans = max(ans,count);
            }

        }
        return ans;
    }
};