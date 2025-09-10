/*
PROBLEM: Create Sorted Array through Instructions
Insert elements left-to-right into sorted array. Cost = min(smaller_count, larger_count).

APPROACH: Segment Tree with Coordinate Compression + Left-to-Right Processing

KEY INSIGHTS:
1. Process LEFT-TO-RIGHT (natural order of instructions)
2. For each element: count existing smaller/larger elements, then add to tree
3. Cost = min(count < val, count > val)

COORDINATE COMPRESSION:
- Maps unique instruction values to segment tree positions
- Handles any range of values efficiently: O(unique elements) space

ORDER MATTERS:
- Count FIRST: "How many elements currently in container are smaller/larger?"
- Add AFTER: "Insert current element into container for future queries"
- This matches the problem's insertion process

SEGMENT TREE OPERATIONS:
- Complete overlap: query range ⊇ segment range → return full count
- No overlap: query range ∩ segment range = ∅ → return 0
- Partial overlap: recurse to children
*/

class SegTree {
    vector<int> seg;              // Frequency count at each node
    vector<long long> values;     // Coordinate compression: position → actual value
    int n;
    
public:
    // Build coordinate compression from unique values in instructions
    SegTree(vector<int>& instructions) {
        set<int> unique_vals;
        for (int val : instructions) unique_vals.insert(val);
        for (int val : unique_vals) values.push_back(val);
        n = values.size();
        seg.resize(4 * n, 0);
    }
    
    void update(int curr, int left, int right, long long val) {
        if (left > right) return;
        if (left == right) {
            seg[curr]++;  // Increment frequency of this value
            return;       // CRITICAL: Must return to avoid double counting
        }
        
        // Find position of val in coordinate system
        int pos = lower_bound(values.begin(), values.end(), val) - values.begin();
        int mid = left + (right - left) / 2;
        
        if (pos <= mid) {
            update(2 * curr + 1, left, mid, val);
        } else {
            update(2 * curr + 2, mid + 1, right, val);
        }
        
        // Update parent with sum of children
        seg[curr] = seg[2 * curr + 1] + seg[2 * curr + 2];
    }
    
    long long query(int curr, int left, int right, long long query_left, long long query_right) {
        if (left > right) return 0;
        
        // Convert segment tree positions to actual values for comparison
        long long segment_left_val = values[left];
        long long segment_right_val = values[right];
        
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
    
    void add(long long val) {
        update(0, 0, n - 1, val);
    }
    
    int getCount(long long lower, long long upper) {
        return query(0, 0, n - 1, lower, upper);
    }
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        SegTree seg(instructions);
        long long total_cost = 0;  // Use long long to prevent overflow before modulo
        const int MOD = 1e9 + 7;
        
        // Process LEFT-TO-RIGHT: simulate the insertion process
        for (int val : instructions) {
            // Count elements currently in container that are smaller/larger
            int smaller_count = seg.getCount(LLONG_MIN, val - 1);  // Elements < val
            int larger_count = seg.getCount(val + 1, LLONG_MAX);   // Elements > val
            
            // Calculate insertion cost BEFORE adding element
            int cost = min(smaller_count, larger_count);
            total_cost = (total_cost + cost) % MOD;
            
            // Add current element to container for future queries
            seg.add(val);
        }
        
        return total_cost;
    }
};

/*
EXAMPLE TRACE: instructions = [1,5,6,2]
Coordinate compression: values = [1, 2, 5, 6]

val=1: smaller=0, larger=0, cost=0, add 1, container=[1]
val=5: smaller=1, larger=0, cost=0, add 5, container=[1,5]  
val=6: smaller=2, larger=0, cost=0, add 6, container=[1,5,6]
val=2: smaller=1, larger=2, cost=1, add 2, container=[1,2,5,6]

Total cost = 1 ✓

KEY DIFFERENCES FROM PREVIOUS PROBLEMS:
- Count Smaller: Only count elements < current (right-to-left)
- Range Sum: Count prefix sums in specific range (right-to-left)  
- This Problem: Count both < and > current, take minimum (left-to-right)

All use same segment tree template with different query patterns!
*/
