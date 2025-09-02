/*
SOLUTION APPROACH: Horizontal Trapezoid Counting via Line Pair Combinations

PROBLEM: Count horizontal trapezoids formed by 4 distinct points
- Horizontal trapezoid = quadrilateral with at least one pair of horizontal sides
- Horizontal sides = parallel to x-axis (same y-coordinate)

KEY INSIGHT: Trapezoid Formation
- Need 2 horizontal lines (each formed by 2+ points with same y-coordinate)
- Each horizontal line can be formed by C(points_on_line, 2) ways
- Trapezoid = choosing 1 pair from first line + 1 pair from second line

MATHEMATICAL APPROACH:
- Group points by y-coordinate
- For each y-level with k points: C(k,2) possible horizontal line segments
- Count trapezoids = sum of (lines_from_y1 × lines_from_y2) for all y1 < y2

OPTIMIZATION: Incremental Calculation
- Instead of nested loops over all y-pairs, use running sum
- For each new y-level: multiply its line count by all previous line counts
- Formula: res += current_lines × total_previous_lines

ALGORITHM:
1. Count points at each y-coordinate
2. For each y-level, calculate C(count, 2) horizontal lines possible
3. Add (new_lines × existing_lines) to result
4. Update running total of lines processed

WHY IT WORKS: Equivalent to pairwise multiplication
- (s0×s1 + s0×s2 + s0×s3 + s1×s2 + s1×s3 + s2×s3)
- = s0×(s1+s2+s3) + s1×(s2+s3) + s2×s3
- This is exactly what the incremental approach computes
*/

class Solution {
public:
    const int mod = 1e9 + 7;
    
    long long calculateNC2(int n) {
        return ((long long)n * (n - 1)) / 2;
    }
    
    int countTrapezoids(vector<vector<int>>& points) {
        long long res = 0;
        long long count = 0;  // Running total of horizontal lines processed
        
        // Group points by y-coordinate
        unordered_map<int, int> yFreq;
        for (auto& point : points) {
            yFreq[point[1]]++;
        }
        
        // For each y-level, calculate contribution to trapezoid count
        for (auto& [y, pointCount] : yFreq) {
            // Number of horizontal line segments at this y-level
            long long lines = calculateNC2(pointCount);
            
            // Add trapezoids formed by pairing this y-level with all previous y-levels
            res = (res + count * lines) % mod;
            
            // Update running total of horizontal lines
            count = (count + lines) % mod;
        }
        
        return res;
    }
};
