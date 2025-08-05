class Solution {
public:
    int totalFruit(vector<int>& f) {
        int i = 0 , j = 0,n = f.size();
        map<int,int> mp;
        int ans = 0;

        while(j < n)
        {
            if(mp.size() == 0){
                mp[f[j]]++;
            }
            else if(mp.size() == 1){
                mp[f[j]]++;
            }
            else {
                int flag = 0;
                for(auto it : mp){
                    if(it.first == f[j]){
                        mp[it.first]++;
                        flag = 1;
                    }
                }

                if(flag == 0){
                    while(mp.size() != 1){
                        mp[f[i]]--;
                        if(mp[f[i]] == 0){
                            mp.erase(f[i]);
                        }
                        i++;
                    }
                    mp[f[j]]++;

                }

            }

            ans = max(ans,j-i + 1);
            j++;

        }
        return ans;
    }
};