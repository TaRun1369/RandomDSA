class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<int,vector<int>> actTomapped;
        vector<int> ans;
        for(auto it : nums){

            int num = it;
            int changed = 0;
            if(num == 0){
                changed = mapping[0];
            }
            string s = "";
            while(num != 0){

                int digit = num%10;
                s += to_string(mapping[digit]);
                // changed = 10*changed + mapping[digit];cout<<num<<" "<<changed<<endl;
                num/=10;
            }
            
            // string s = to_string(changed);
            reverse(s.begin(),s.end());
            if(s != "")
            changed = stoi(s);
            actTomapped[changed].push_back(it);
        }
        cout<<"map"<<endl;
        for(auto it : actTomapped){
            cout<<it.first<<endl;
            
            for(auto iss : it.second){
                cout<<iss<<" ";
                ans.push_back(iss);
            }
            cout<<endl;
        }
        return ans;
    }
};