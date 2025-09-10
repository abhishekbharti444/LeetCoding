/*
PROBLEM: Count Range Sums
Given array nums, count how many range sums S(i,j) = sum(nums[i..j]) are in [lower, upper]

KEY INSIGHT: Range sum S(i,j) = prefixSum[j] - prefixSum[i-1]
So we need: lower ≤ prefixSum[j] - prefixSum[i-1] ≤ upper

ALGORITHM APPROACH:
1. Process array RIGHT-TO-LEFT 
2. At each position, add current prefixSum to segment tree
3. Query: how many previously added prefixSums can form valid ranges with current position

WHY RIGHT-TO-LEFT:
- When at position i, we want to count ranges ENDING at positions > i
- So we need prefixSums from positions to the right already in our tree

SEGMENT TREE DESIGN:
- Stores FREQUENCY COUNT of prefix sum values (not the sums themselves)
- Uses coordinate compression: maps large prefix sum values to small indices
- values[] array: position → actual prefix sum value mapping

QUERY LOGIC:
- curr_sum represents prefixSum[i-1] (left boundary of range)
- Tree contains prefixSum[j] values where j > i (right boundaries)
- For valid range: lower ≤ prefixSum[j] - prefixSum[i-1] ≤ upper
- Rearranging: prefixSum[j] ∈ [prefixSum[i-1] + lower, prefixSum[i-1] + upper]
- So query: getCount(curr_sum + lower, curr_sum + upper)

SEGMENT TREE OPERATIONS:
- Complete overlap: query range completely contains segment → return full count
- No overlap: query range and segment don't intersect → return 0  
- Partial overlap: recurse to children
*/

class SegTree {
    vector<int> seg;           // Frequency count at each node
    vector<long long> values;  // Coordinate compression: position → actual value
    int n;
    
public:
    // Build coordinate compression from all possible prefix sum values
    SegTree(vector<long long>& vals) {
        set<long long> unique_vals;
        for (auto val : vals) unique_vals.insert(val);
        for (auto val : unique_vals) values.push_back(val);
        n = values.size();
        seg.resize(4 * n, 0);
    }
    
    void update(int curr, int left, int right, long long val) {
        if (left == right) {
            seg[curr]++;  // Increment frequency of this value
            return;
        }
        
        int mid = left + (right - left) / 2;
        // Find position of val in our coordinate system
        int pos = lower_bound(values.begin(), values.end(), val) - values.begin();
        
        if (pos <= mid) {
            update(2 * curr + 1, left, mid, val);
        } else {
            update(2 * curr + 2, mid + 1, right, val);
        }
        
        seg[curr] = seg[2 * curr + 1] + seg[2 * curr + 2];
    }
    
    int query(int curr, int left, int right, long long query_left, long long query_right) {
        if (left > right) return 0;
        
        // Convert segment tree positions to actual values
        long long segment_left_val = values[left];
        long long segment_right_val = values[right];
        
        // Complete overlap: query range completely contains segment range
        // [query_left, query_right] ⊇ [segment_left_val, segment_right_val]
        if (query_left <= segment_left_val && segment_right_val <= query_right) {
            return seg[curr];
        }
        
        // No overlap: ranges don't intersect at all
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
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        // Generate all prefix sums for coordinate compression
        vector<long long> prefix_sums;
        long long curr_sum = 0;
        for (int num : nums) {
            curr_sum += num;
            prefix_sums.push_back(curr_sum);
        }
        
        SegTree seg(prefix_sums);
        int count = 0;
        
        // Process RIGHT-TO-LEFT: build up available right boundaries as we go
        for (int i = nums.size() - 1; i >= 0; i--) {
            // Add current prefix sum as potential right boundary
            seg.add(curr_sum);
            
            // Move to previous prefix sum (this becomes left boundary)
            curr_sum -= nums[i];
            
            // Count valid ranges: curr_sum is prefixSum[i-1], tree has prefixSum[j] where j >= i
            // Want: lower ≤ prefixSum[j] - prefixSum[i-1] ≤ upper
            // So: prefixSum[j] ∈ [prefixSum[i-1] + lower, prefixSum[i-1] + upper]
            count += seg.getCount(curr_sum + lower, curr_sum + upper);
        }
        
        return count;
    }
};

/*
EXAMPLE TRACE: nums = [1, -2, 3], lower = 0, upper = 2
Prefix sums: [1, -1, 2]

i=2: curr_sum=2, add 2 to tree, curr_sum=2-3=-1, query(-1+0, -1+2)=(-1,1), tree={2}, count=0
i=1: curr_sum=-1, add -1 to tree, curr_sum=-1-(-2)=1, query(1+0, 1+2)=(1,3), tree={2,-1}, count=1 (found 2)  
i=0: curr_sum=1, add 1 to tree, curr_sum=1-1=0, query(0+0, 0+2)=(0,2), tree={2,-1,1}, count=2 (found 1,2)

Final count = 3 ✓
*/
