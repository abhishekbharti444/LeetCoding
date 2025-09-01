/*
SOLUTION APPROACH: BFS with Prime Teleportation using Global Prime Array

OPTIMIZATION: Use global prime array to avoid repeated memory allocation
- Global arrays are faster to access and don't require repeated initialization
- Lazy initialization ensures sieve is computed only once across multiple test cases
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
        // Lazy initialization - fill prime array only once
        if (is_prime[0]) fillPrime();
        
        vector<int> A = nums;
        int n = A.size();
        queue<int> q;
        vector<int> dist(n, -1);
        q.push(0);
        dist[0] = 0;
        int max_el = *max_element(A.begin(), A.end());
        
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < A.size(); ++i) {
            mp[A[i]].push_back(i);
        }

        unordered_set<int> vis;
        
        while (!q.empty()) {
            int curr_index = q.front();
            q.pop();
            
            // Adjacent moves
            if (curr_index - 1 >= 0 && dist[curr_index - 1] == -1) {
                dist[curr_index - 1] = dist[curr_index] + 1;
                q.push(curr_index - 1);
            }

            if (curr_index + 1 < n && dist[curr_index + 1] == -1) {
                dist[curr_index + 1] = dist[curr_index] + 1;
                q.push(curr_index + 1);
            }
            
            // Prime teleportation
            if (!is_prime[A[curr_index]] || vis.contains(A[curr_index])) continue;
            
            for (int next = A[curr_index]; next <= max_el; next += A[curr_index]) {
                if (!mp.contains(next)) continue;
                for (auto el : mp[next]) {
                    if (dist[el] != -1) continue;
                    q.push(el);
                    if (el == n-1) return dist[curr_index] + 1;
                    dist[el] = dist[curr_index] + 1;
                }
            }
            vis.insert(A[curr_index]);
        }
        
        return dist[n-1];
    }
};
