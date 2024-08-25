class Solution {
public:
    int titleToNumber(string c) {
        long long ans = 0;
        int n = c.size();
        map<int,long long>mp;
        mp[1] = 26;
        mp[2] = pow(26,2) + mp[1];mp[3] = pow(26,3) + mp[2];mp[4] = pow(26,4) + mp[3];
        mp[5] = pow(26,5) + mp[4];mp[6] = pow(26,6) + mp[5];
        ans += mp[n - 1];
        int rem = 0;
        cout<<ans<<endl;
        for(int i = n- 1;i>=0;i--){
            // cout<<"lund - "<<(rem)*pow(26,(n - i - 1))<<endl;
            ans += (rem)*pow(26,(n - i - 1));
            if(i - 1 >= 0)
            rem = c[i - 1] - 'A';
        }
        ans += (c[n-1] - 'A');
        return ans + 1;
    }
};