class Solution {
public:
        /*
        Greedy solution :
            Time = O(N)
            Space = O(1)
            
            We can iterate over all indices maintaining the furthest reachable position from current index - max_reach and currently furthest reached position - last_jump_pos. Everytime we will try to update last_jump_pos to furthest possible reachable index - max_reach.

            Updating the last_jump_pos separately from max_reach allows us to maintain track of minimum jumps required. Each time last_jump_pos is updated, jumps will also be updated and store the minimum jumps required to reach last_jump_pos (On the contrary, updating jumps with max_reach won't give the optimal (minimum possible) value of jumps required).

            We will just return it as soon as last_jump_pos reaches(or exceeds) last index.
    */ 
    int jump(vector<int>& nums) {
        int last_jump = 0;
        int n = nums.size();
        int res = 0;
        int max_reach = 0;
        for (int i = 0; last_jump < n-1; ++i) {
            max_reach = max(max_reach, i + nums[i]);
            if (i == last_jump) {
                last_jump = max_reach;
                res++;
            }
        }
        return res;
    }
};