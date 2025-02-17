class RangeFreqQuery {
public:
    vector<unordered_map<int, int>> seg;
    int n;

    // Build segment tree
    void build(int ind, int low, int high, vector<int> &arr) {
        if (low == high) {
            seg[ind][arr[low]]++;  // Store frequency of single element
            return;
        }

        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);

        // Merge frequency maps of left and right child
        seg[ind] = seg[2 * ind + 1];
        for (auto &p : seg[2 * ind + 2]) {
            seg[ind][p.first] += p.second;
        }
    }

    // Query function to find frequency of `value` in range [l, r]
    int queryUtil(int ind, int low, int high, int l, int r, int value) {
        // No overlap
        if (r < low || high < l) return 0;

        // Complete overlap
        if (low >= l && high <= r) {
            return seg[ind][value];  // Return frequency of `value`
        }

        // Partial overlap
        int mid = (low + high) / 2;
        return queryUtil(2 * ind + 1, low, mid, l, r, value) +
               queryUtil(2 * ind + 2, mid + 1, high, l, r, value);
    }

    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    int query(int left, int right, int value) {
        return queryUtil(0, 0, n - 1, left, right, value);
    }
};
