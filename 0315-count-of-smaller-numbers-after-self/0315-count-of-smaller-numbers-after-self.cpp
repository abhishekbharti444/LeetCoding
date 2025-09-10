/*
PROBLEM: Count Smaller Numbers After Self
For each element, count how many elements to its RIGHT are smaller than it.

APPROACH: Segment Tree with Coordinate Compression + Right-to-Left Processing

KEY INSIGHTS:
1. Process RIGHT-TO-LEFT to build up elements as we go
2. For each position i: count elements already processed (to the right) that are < nums[i]
3. Use coordinate compression to handle any range of values efficiently

COORDINATE COMPRESSION:
- Problem: Values can be large/negative, can't use as direct array indices
- Solution: Map unique values to positions 0,1,2,... in segment tree
- values[] array: position → actual value mapping
- Space: O(unique elements) instead of O(max_value - min_value)

SEGMENT TREE DESIGN:
- Stores frequency count of each value (not the values themselves)
- Each node represents count of elements in its value range
- Query: count elements in range [lower, upper]

ORDER MATTERS:
- Count FIRST: "How many elements to the right are smaller?"
- Add AFTER: "Make current element available for future queries"
- If we add first, we'd count the current element itself (wrong!)

SEGMENT TREE OPERATIONS:
- Complete overlap: query range ⊇ segment range → return full count
- No overlap: query range ∩ segment range = ∅ → return 0
- Partial overlap: recurse to children
*/

class SegTree {
    vector<int> seg;           // Frequency count at each node
    vector<int> values;        // Coordinate compression: position → actual value
    int n;
    
public:
    // Build coordinate compression from unique values in input
    SegTree(vector<int>& nums) {
        set<int> unique_vals;
        for (int val : nums) unique_vals.insert(val);
        for (int val : unique_vals) values.push_back(val);
        n = values.size();
        seg.resize(4 * n, 0);
    }
    
    void update(int curr, int left, int right, int val) {
        if (left == right) {
            seg[curr]++;  // Increment frequency of this value
            return;       // CRITICAL: Must return to avoid double counting
        }
        
        int mid = left + (right - left) / 2;
        // Find position of val in coordinate system
        int pos = lower_bound(values.begin(), values.end(), val) - values.begin();
        
        if (pos <= mid) {
            update(2 * curr + 1, left, mid, val);
        } else {
            update(2 * curr + 2, mid + 1, right, val);
        }
        
        // Update parent with sum of children
        seg[curr] = seg[2 * curr + 1] + seg[2 * curr + 2];
    }
    
    int query(int curr, int left, int right, int query_left, int query_right) {
        if (left > right) return 0;
        
        // Convert segment tree positions to actual values for comparison
        int segment_left_val = values[left];
        int segment_right_val = values[right];
        
        // Complete overlap: query range completely contains segment range
        // [query_left, query_right] ⊇ [segment_left_val, segment_right_val]
        if (query_left <= segment_left_val && query_right >= segment_right_val) {
            return seg[curr];
        }
        
        // No overlap: ranges don't intersect
        if (query_left > segment_right_val || query_right < segment_left_val) {
            return 0;
        }
        
        // Partial overlap: need to check children
        int mid = left + (right - left) / 2;
        return query(2 * curr + 1, left, mid, query_left, query_right) +
               query(2 * curr + 2, mid + 1, right, query_left, query_right);
    }
    
    void add(int val) {
        update(0, 0, n - 1, val);
    }
    
    int getCount(int lower, int upper) {
        return query(0, 0, n - 1, lower, upper);
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        SegTree seg(nums);
        vector<int> result(nums.size());
        
        // Process RIGHT-TO-LEFT: build up processed elements as we go
        for (int i = nums.size() - 1; i >= 0; i--) {
            // Count elements already processed (to the right) that are smaller
            result[i] = seg.getCount(INT_MIN, nums[i] - 1);
            
            // Add current element to tree for future queries
            seg.add(nums[i]);
        }
        
        return result;
    }
};

/*
EXAMPLE TRACE: nums = [5, 2, 6, 1]
Coordinate compression: values = [1, 2, 5, 6] (positions 0,1,2,3)

i=3: count < 1, tree={}, result[3] = 0, add 1
i=2: count < 6, tree={1}, result[2] = 1, add 6  
i=1: count < 2, tree={1,6}, result[1] = 1, add 2
i=0: count < 5, tree={1,6,2}, result[0] = 2, add 5

Final result = [2,1,1,0] ✓

WHY THIS WORKS:
- Coordinate compression handles any value range efficiently
- Right-to-left processing ensures we only count elements to the right
- Segment tree gives O(log n) updates and queries
- Total complexity: O(n log n)
*/
