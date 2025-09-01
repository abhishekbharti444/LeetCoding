/*
SOLUTION APPROACH: BFS with Prime Teleportation Optimization

PROBLEM: Find minimum jumps from index 0 to n-1 using:
1. Adjacent moves: jump to i±1 (cost: 1 jump)
2. Prime teleportation: if nums[i] is prime p, jump to any j where nums[j] % p == 0 (cost: 1 jump)

ALGORITHM: BFS for shortest path
1. Use BFS since we want minimum number of jumps (unweighted shortest path)
2. From each position, explore all possible moves:
   - Adjacent: try i-1 and i+1 if within bounds
   - Prime teleportation: if nums[i] is prime, jump to all positions with multiples

KEY OPTIMIZATIONS:
1. Global Prime Array + Lazy Initialization:
   - Sieve of Eratosthenes computed only once across all test cases
   - Prevents TLE from repeated sieve computation (O(n log log n) each time)

2. Avoid Redundant Prime Processing:
   - Use visited set to track processed prime values
   - If we've already processed prime p from another position, skip it
   - This prevents exponential blowup when same prime appears multiple times

3. Efficient Multiple Finding:
   - For prime p, check multiples p, 2p, 3p, ... up to max_element
   - Use hash map to quickly find all indices with each value
   - Only process multiples that actually exist in the array

COMPLEXITY:
- Time: O(n + max_val × unique_primes/prime + sieve)
- Space: O(n + max_val) for prime array and data structures

CRITICAL INSIGHT: Prime teleportation creates shortcuts but can be expensive
- Must balance thorough exploration with avoiding redundant work
- Lazy initialization prevents repeated sieve computation across test cases
*/

vector<bool> is_prime(1e6 + 1, true);

class Solution {
public:
    void fillPrime() {
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= 1e6; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= 1e6; j += i) {
                    is_prime[j] = false;
                }
            }
        }
    }
    
    int minJumps(vector<int>& nums) {
        // Lazy initialization: compute sieve only once across all test cases
        if (is_prime[0]) fillPrime();
        
        int n = nums.size();
        queue<int> q;
        vector<int> dist(n, -1);
        q.push(0);
        dist[0] = 0;
        int max_el = *max_element(nums.begin(), nums.end());
        
        // Precompute positions for each value (for teleportation lookup)
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        // Track processed primes to avoid redundant teleportation computation
        unordered_set<int> vis;
        
        while (!q.empty()) {
            int curr_index = q.front();
            q.pop();
            
            // Adjacent moves: try i-1 and i+1
            if (curr_index - 1 >= 0 && dist[curr_index - 1] == -1) {
                dist[curr_index - 1] = dist[curr_index] + 1;
                q.push(curr_index - 1);
            }

            if (curr_index + 1 < n && dist[curr_index + 1] == -1) {
                dist[curr_index + 1] = dist[curr_index] + 1;
                q.push(curr_index + 1);
            }
            
            // Prime teleportation: only if current value is unprocessed prime
            if (!is_prime[nums[curr_index]] || vis.contains(nums[curr_index])) continue;
            
            // Find all multiples of current prime and teleport to their positions
            for (int next = nums[curr_index]; next <= max_el; next += nums[curr_index]) {
                if (!mp.contains(next)) continue;
                for (auto el : mp[next]) {
                    if (dist[el] != -1) continue;  // Already visited
                    q.push(el);
                    if (el == n-1) return dist[curr_index] + 1;  // Early termination
                    dist[el] = dist[curr_index] + 1;
                }
            }
            vis.insert(nums[curr_index]);  // Mark this prime as processed
        }
        
        return dist[n-1];
    }
};
