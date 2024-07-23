// class Solution {
// public:
//      map<int,int> mp;
//      bool cmp(int a,int b){
//         if(mp[a] > mp[b]){
//             return b > a;
//         }
//         else {
//            return  a > b;
//         }

//      }
//     vector<int> frequencySort(vector<int>& nums) {
       
//         for(auto it : nums){
//             mp[it]++;
//         }
//         sort(nums.begin(),nums.end(),cmp);
//         return nums;
//     }
// };


class Solution {
public:
    map<int, int> mp;

    // Custom comparator for sorting
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second < b.second;
    }

    vector<int> frequencySort(vector<int>& nums) {
        // Count frequencies
        for (int num : nums) {
            mp[num]++;
        }

        // Create a vector of pairs (element, frequency)
        vector<pair<int, int>> freqVec;
        for (auto& it : mp) {
            freqVec.push_back(it);
        }

        // Sort using custom comparator
        sort(freqVec.begin(), freqVec.end(), cmp);

        // Build the result vector based on sorted order
        vector<int> result;
        for (auto& it : freqVec) {
            for (int i = 0; i < it.second; i++) {
                result.push_back(it.first);
            }
        }

        return result;
    }
};
