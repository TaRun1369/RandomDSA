class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> v = arr;
        sort(v.begin(),v.end());
        int n = arr.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        int j = 1;
        int prev = INT_MIN;
        // for(auto it : v){
        //     cout<<it<<" "<<i<< " "<<prev<<endl;
        //     if(it == prev){
        //         mp[it] = i;
        //     }
        //     else{
        //         mp[it] = i;
        //         i++;
        //     }
        //     prev = it;
            
        // }

        for(int i = 0;i<n;i++){
            mp[v[i]] = j;
            if(i < n-1 && v[i] != v[i + 1]){
                j++;
            }
        }

        for(auto it : arr){
            ans.push_back(mp[it]);
        }

        return ans;
    }
};