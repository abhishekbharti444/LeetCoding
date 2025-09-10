class SegTree {
    vector<int> seg;
    vector<long long> values;
    int n;
public:
    SegTree(vector<int>& A) {
        set<int> uni;
        for (int a:A) uni.insert(a);
        for (int a: uni) values.push_back(a);
        n = values.size();
        seg.resize(4*n, 0);
    }

    void update(int curr, int left, int right, long long val) {
        if (left > right) return;
        if (left == right) {
            seg[curr]++;
            return;
        }

        int pos = lower_bound(values.begin(), values.end(), val) - values.begin();
        int mid = left + (right - left)/2;
        if (pos <= mid) {
            update(2*curr + 1, left, mid, val);
        }
        else update(2 * curr + 2, mid + 1, right, val);
        seg[curr] = seg[2*curr + 1] + seg[2 * curr + 2];
    }
    long long query(int curr, int left, int right, long long qleft, long long qright) {
        if (left > right) return 0;
        // full overlap
        long long left_val = values[left], right_val = values[right];
        if (qleft <= left_val && qright >= right_val) return seg[curr];
        if (qleft > right_val || qright < left_val) return 0;

        int mid = left + (right - left)/2;
        return query(2*curr + 1, left, mid, qleft, qright)
            + query(2*curr + 2, mid + 1, right, qleft, qright);
    }

    void add(long long val) {
        update(0, 0, n-1, val);
    }
    int getCount(int lower, int upper) {
        return query(0, 0, n-1, lower, upper);
    }
};
class Solution {
public:
    int createSortedArray(vector<int>& in) {
        SegTree seg(in);
        long long res = 0;
        const int MOD = 1e9 + 7;
        for (int a : in) {
            int lesser = seg.getCount(INT_MIN, a - 1);
            int great = seg.getCount(a + 1, INT_MAX);
            seg.add(a);
            res = (res + min(lesser, great)) % MOD;
        }
        return res;
    }
};















