class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());

        map<string,int>mp;
        vector<string> ans;
        for(auto it : folder){
            string temp = "";
            int f = 1;
            for(int i = 0;i<it.size();){
                // cout<<it<<" - "<< temp<<endl;
                char ii = it[i];
                if(ii == '/'){ 
                    
                    temp += it[i];i++;
                }
                else{
                    while(i < it.size() && it[i] != '/'){
                        temp += it[i];
                        i++;
                    }
                    // i--;

                    if(mp.find(temp) != mp.end()){
                        f = 0;
                        break;
                    }
                    
                }
            }
            if(f == 1){
                mp[it]++;
                ans.push_back(it);
            }
        }
        return ans;
    }
};