// class Solution {
// public:
//     static bool func(vector<int> &a,vector<int> &b ){
//         return a[0] > b[0];
//     }
//      int lowerBound(vector<vector<int>>& tuple, int x) {
//         int l = 0, r = tuple.size() - 1;
//         int ans = tuple.size(); 
//         while (l <= r) {
//             int mid = l + (r - l) / 2;
//             if (tuple[mid][0] <= x) {
//                 ans = mid;
//                 r = mid - 1; 
//             } else {
//                 l = mid + 1;
//             }
//         }
//         return ans;
//     }
//     int maxProfitAssignment(vector<int>& diff, vector<int>& prof, vector<int>& majdur) {
//         vector<vector<int>> tuple; // diff  prof  maxtillnow
//         int n = prof.size();    
//         for(int i = 0;i<n;i++){
//             tuple.push_back({diff[i],prof[i],0});
//         }

//         sort(tuple.begin(),tuple.end(),func);
//         int ans  = 0;
//         int maxi = 0;
//         for(int i = 0;i<n;i++){

//             maxi = max(maxi,tuple[i][1]);
//             tuple[i][2] = maxi;

//             // int lb = lower_bound(tuple.begin(),tuple.end(),{0,majdur[i],0}) - tuple.begin();
//             int lb = lowerBound(tuple, majdur[i]);
//             ans += tuple[lb][2];
//         }
//         return ans;
//     }
// };

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0]; // ascending order of difficulty
    }

    // Custom lower_bound: find the last job where diff <= skill
    int lowerBound(vector<vector<int>>& jobs, int skill) {
        int l = 0, r = jobs.size() - 1;
        int ans = -1; // default if no job is doable
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (jobs[mid][0] <= skill) {
                ans = mid;
                l = mid + 1; // go right to find higher but still <= skill
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

    int maxProfitAssignment(vector<int>& diff, vector<int>& prof, vector<int>& majdur) {
        int n = diff.size();
        vector<vector<int>> jobs; 

        for (int i = 0; i < n; ++i) {
            jobs.push_back({diff[i], prof[i], 0});
        }

        sort(jobs.begin(), jobs.end(), cmp);

        int maxProfit = 0;
        for (int i = 0; i < n; ++i) {
            maxProfit = max(maxProfit, jobs[i][1]);
            jobs[i][2] = maxProfit; 
        }

        int total = 0;
        for (int i = 0; i < majdur.size(); ++i) {
            int idx = lowerBound(jobs, majdur[i]);
            if (idx != -1) {
                total += jobs[idx][2];
            }
        }

        return total;
    }
};
