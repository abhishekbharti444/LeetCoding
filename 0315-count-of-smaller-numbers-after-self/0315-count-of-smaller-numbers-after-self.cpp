class SegTree {
    vector<int> seg;
    vector<int> values;
    int n;
public:
    SegTree(vector<int>& A) {
        set<int> uni;
        for (int a: A) uni.insert(a);
        for (int a: uni) values.push_back(a);
        n = values.size();
        seg.resize(4*n, 0);
    }

    void update(int curr, int left, int right, int val) {
        if (left > right) return;
        if (left == right) {
            seg[curr]++;
            return;
        }
        int mid = left + (right - left)/2;
        int pos = lower_bound(values.begin(), values.end(), val) - values.begin();
        if (pos <= mid) {
            update(2 * curr + 1, left, mid, val);
        }
        else update(2 * curr + 2, mid + 1, right, val);

        seg[curr] = seg[2*curr + 1] + seg[2 * curr + 2];
    }

    int query(int curr, int left, int right, int qleft, int qright) {
        if (left > right) return 0;
        // Complete overlap
        int left_val = values[left], right_val = values[right];
        if (qleft <= left_val && qright >= right_val) return seg[curr];
        if (qleft > right_val || qright < left_val) return 0;

        int mid = left + (right - left)/2;
        return query(2 * curr + 1, left, mid, qleft, qright) +
                query(2 * curr + 2, mid + 1, right, qleft, qright);
    }
    void add(int val) {
        update(0, 0, n-1, val);
    }
    int getCount(int lower, int upper) {
        return query(0, 0, n-1, lower, upper);
    }

};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        SegTree seg(nums);
        vector<int> res(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] = seg.getCount(INT_MIN, nums[i] - 1);
            seg.add(nums[i]);
        }
        return res;
    }
};