#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> bitLeft, bitRight;
    int n;

    void update(vector<int> &bit, int i, int val) {
        for (; i <= n; i += i & -i) {
            bit[i] += val;
        }
    }

    int query(vector<int> &bit, int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += bit[i];
        }
        return sum;
    }

    int numTeams(vector<int>& rating) {
        n = rating.size();
        bitLeft.resize(n + 1, 0);
        bitRight.resize(n + 1, 0);

        vector<int> sortedRating = rating;
        sort(sortedRating.begin(), sortedRating.end());
        for (int &r : rating) {
            r = lower_bound(sortedRating.begin(), sortedRating.end(), r) - sortedRating.begin() + 1;
        }

        for (int r : rating) {
            update(bitRight, r, 1);
        }

        int numTeams = 0;

        for (int i = 0; i < n; ++i) {
            int r = rating[i];
            update(bitRight, r, -1);

            int leftLess = query(bitLeft, r - 1);
            int leftGreater = i - query(bitLeft, r);

            int rightLess = query(bitRight, r - 1);
            int rightGreater = (n - i - 1) - query(bitRight, r);

            numTeams += leftLess * rightGreater + leftGreater * rightLess;

            update(bitLeft, r, 1);
        }

        return numTeams;
    }
};
