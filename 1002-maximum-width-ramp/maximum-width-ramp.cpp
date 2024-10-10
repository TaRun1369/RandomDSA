class Solution {
public:
    void ps(stack<pair<int,int>> st){
        while(!st.empty()){
            cout<<st.top().first<<" ";
            st.pop();
        }
        cout<<endl;
    }
    int maxWidthRamp(vector<int>& nums) {

        stack<pair<int,int>> st;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            int it = nums[i];
            // cout<<"ele - "<<it<<endl;
            if(st.empty() || st.top().first > it){
                st.push({it,i});
            }
            else{
                vector<pair<int,int>> v;
                while(!st.empty()){
                    if(st.top().first > it) break;
                    ans = max(ans,(i - st.top().second));
                    v.push_back(st.top());
                    st.pop();
                }
                reverse(v.begin(),v.end());
                for(auto ii : v){
                    // cout<<ii.first<<" ";
                    st.push(ii);
                }
            }
            // cout<<"stack"<<endl;
            // ps(st);
            
            // cout<<ans<<endl;
        }

        return ans;
    }
};