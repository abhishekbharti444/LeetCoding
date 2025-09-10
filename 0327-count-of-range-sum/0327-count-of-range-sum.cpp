class SegTree {
    vector<int> seg;
    vector<long long> values;
    int n;
public:
    SegTree(vector<long long>& vals) {
        set<long long> uni;
        for (auto el: vals) uni.insert(el);
        for (auto el: uni) values.push_back(el);
        n = values.size();
        seg.resize(4*n, 0);
    }
    int merge(int a, int b) {
        return a + b;
    }
    void update(int curr, int left, int right, long long val) {
        if (left == right) {
            seg[curr]++;
            return;
        }
        int mid = left + (right - left)/2;
        int pos = lower_bound(values.begin(), values.end(), val) - values.begin();
        if (pos <= mid) update(2 * curr + 1, left, mid, val);
        else update(2 * curr + 2, mid + 1, right, val);
        seg[curr] = merge(seg[2*curr + 1], seg[2 * curr + 2]);
    }
    int query(int curr, int left, int right, long long qleft, long long qright)  {
        if (left > right) return 0;
        long long left_val = values[left], right_val = values[right];
        // complete overlap(query range completely contains the segment tree)
        if (qleft <= left_val && qright >= right_val) return seg[curr];

        // No overlap
        if (qleft > right_val || qright < left_val) return 0;

        int mid = left + (right - left)/2;
        return query(2 * curr + 1, left, mid, qleft, qright) 
                + query(2 * curr + 2, mid + 1, right, qleft, qright);
    }

    void add(long long val) {
        update(0, 0, n-1, val);
    }
    int getCount(long long lower, long long upper) {
        return query(0, 0, n-1, lower, upper);
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> preSums;
        long long curr_sum = 0;
        for (int a: nums) {
            curr_sum += a;
            preSums.push_back(curr_sum);
        }
        SegTree seg(preSums);
        int count = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            seg.add(curr_sum);
            curr_sum -= nums[i];
            count += seg.getCount(lower + curr_sum, upper + curr_sum);
        }
        return count;
    }
};