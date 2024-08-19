class Solution {
public:
// vector<int> ans;

int longDivisors(long long n){
    int sum = INT_MAX;
    for(long long i = 2;i*i<=n;i++){
        if(n%i==0){
            // cout<<i<<endl;
            // ans.push_back(i);
            // if(i != n/i)
            // cout<<n/i<<endl;
            // ans.push_back(n/i);
            if(i + (n/i) < sum){
                sum = longDivisors(i) + longDivisors(n/i);
            }

        }
    }
    if(sum != INT_MAX)
    return sum;
    else return n;
}
    int minSteps(int n) {
        // return recur(n);
        if(n == 1) return 0;
        int anss = longDivisors(n);
        // int anss = accumulate(ans.begin(),ans.end(),0);
        if(anss != INT_MAX)
        return anss;
        else return n;
    }
    // 11 -> 1011 = 6 
    // 3 -> 011 = 3 
    // 7 -> 111 = 5
    // 33  -> 100001 = 7


};