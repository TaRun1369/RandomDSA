#define ll int

class Solution {
public:
    vector<ll> z_algo(vector<int> str){
    ll len = str.size();
    ll l = 0,r = 0;
    vector<ll> z(len);
    for(ll i = 1;i < len;i++){
        if(i > r){
            // cout<<"i - "<<i<<"  yaha"<<endl;
            l = r = i;
            while(r < len and str[r] == str[r - l]){
                r++;
            }
            z[i] = r - l;
            r--;
        }
        else{
            ll idx = i - l;
            if(i + z[idx] <= r)
                z[i] = z[idx];
            else{
                l = i;
                while(r < len and str[r] == str[r - l]){
                    r++;
                }
                z[i] = r - l;
                r--;
            }
        }
    }
    return z;
}

    int beautifulSplits(vector<int>& nums) {
        vector<int> z;
        int n = nums.size();
        z = z_algo(nums);
        int res = 0;
        for(int i = 1;i<n - 1;i++){
            vector<int> rem(nums.begin() + i,nums.end());
            vector<int> z2 = z_algo(rem);
            for(int j = i + 1;j<n;j++){
                if((j >= i + i && z[i] >= i)  || (z2[j - i] >= j - i)) res++;
            }
        }
        return res;
    }
};