class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n,0),ans1(n,0);
        int noo = 0,sum = 0;
        for(int i = n-1;i>=0;i--){
            ans[i] += (sum + noo);
            noo += (boxes[i] - '0');
            sum = ans[i];
            // cout<<ans[i]<<" ";
        }
        sum = 0,noo = 0;
        for(int i = 0;i<n;i++){
            // cout<<boxes[i]<<ans1[i]<<noo<<sum<<endl;
            ans1[i] += (sum + noo);
            noo += (boxes[i] - '0');
            sum = ans1[i];
        }
        for(int i = 0;i<n;i++){
            ans[i] += ans1[i];
        }
        return ans;

    }
};