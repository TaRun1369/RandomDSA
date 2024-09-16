class Solution {
public:
    int calc(string a,string b){
        string asub = a.substr(3,2);
        string bsub = b.substr(3,2);
        string ashr = a.substr(0,2);
        string bshr = b.substr(0,2);

        int ans = 0;
        int amin = stoi(asub),bmin = stoi(bsub);
        int ahr = stoi(ashr),bhr = stoi(bshr);
        if(amin < bmin){
            ans += bmin - amin;
            ans += ((60) * (bhr - ahr));
        }
        else{
            ans += bmin;
            ans += (60 - amin);
            ans +=( (60) * (bhr - ahr - 1));
        }
        return ans;

    }
    int findMinDifference(vector<string>& t) {
        sort(t.begin(),t.end());
        int n = t.size();
        int mini = calc("00:00",t[0]) + calc(t[n-1] , "24:00");

        for(int i = 0 ;i<n - 1;i++){
            mini = min(mini,calc(t[i],t[i + 1]));
        }

        return mini;
    }
};