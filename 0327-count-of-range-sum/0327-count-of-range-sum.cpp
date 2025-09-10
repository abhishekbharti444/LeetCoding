class SegTree {
    vector<int> seg;
    vector<long> values;
    int n;
public:
    SegTree(vector<long>& vals) {
        values = vals;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());
        n = values.size();
        seg.resize(4*n, 0);
    }
    
    void update(int curr, int left, int right, long val) {
        if (left == right) {
            seg[curr]++;
            return;
        }
        int mid = left + (right - left)/2;
        int pos = lower_bound(values.begin(), values.end(), val) - values.begin();
        if (pos <= mid) {
            update(2*curr+1, left, mid, val);
        } else {
            update(2*curr+2, mid+1, right, val);
        }
        seg[curr] = seg[2*curr+1] + seg[2*curr+2];
    }
    
    int query(int curr, int left, int right, long minVal, long maxVal) {
        if (left > right) return 0;
        long leftVal = values[left], rightVal = values[right];
        if (minVal <= leftVal && rightVal <= maxVal) return seg[curr];
        if (maxVal < leftVal || minVal > rightVal) return 0;
        
        int mid = left + (right - left)/2;
        return query(2*curr+1, left, mid, minVal, maxVal) + 
               query(2*curr+2, mid+1, right, minVal, maxVal);
    }
    
    void add(long val) { update(0, 0, n-1, val); }
    int getCount(long minVal, long maxVal) { return query(0, 0, n-1, minVal, maxVal); }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> prefixSums;
        long sum = 0;
        for (int num : nums) {
            sum += num;
            prefixSums.push_back(sum);
        }
        
        SegTree seg(prefixSums);
        int count = 0;
        
        for (int i = nums.size()-1; i >= 0; i--) {
            seg.add(sum);
            sum -= nums[i];
            count += seg.getCount(lower + sum, upper + sum);
        }
        
        return count;
    }
};
