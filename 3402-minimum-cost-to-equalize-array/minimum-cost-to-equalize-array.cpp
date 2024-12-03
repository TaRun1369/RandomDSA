class Solution {
public:
    int mod = 1e9 + 7;
    long long solve(long long maxx,int c1,int c2,vector<int> &nums,long long mini,long long sum){
        long long maxdiff = maxx - mini; // target - minimum
        long long n = nums.size(); 
        long long total = maxx*n - sum; // increments required

        if(2*c1 <= c2){
            return 1ll* total * c1;
        }

        long long last = total - maxdiff;
        if(last < maxdiff) return ((maxdiff - last) * c1 + last * c2)*1ll; 
        // if(total / 2 < maxdiff) ye bhi condition likh sakta


        if(total % 2 == 0) return 1ll*((total/2) * c2);
        else return 1ll*((total/2)*c2  +  c1);

    }
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        long long ans = 1e18;
        long long maxi = *max_element(nums.begin(),nums.end())*1ll;

        long long mini = *min_element(nums.begin(),nums.end())*1ll;
        long long sum = accumulate(nums.begin(),nums.end(),0ll);

        for(long long i = maxi;i<= 2*maxi;i++){
            
            ans = min(ans,solve(i,cost1,cost2,nums,mini,sum));

        }
        return ans%mod;    
    }
};