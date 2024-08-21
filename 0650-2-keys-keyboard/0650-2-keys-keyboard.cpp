#define vi vector<int>
#define vvi vector<vi>
class Solution {
public:
    /*
        Pretty straight forward DP. 
        Approach: 
            1. Two decisions are there to be made: 
                1a. When we paste with the clipboard. clip will be same, curr will be curr + clip
                1b. When we copy and paste. clip will become curr, curr will be curr + curr. 
                1c. Notice how we are not doing just the copy operation since it will result into infinite recursion. 
            2. Memoize the result with 2d vector. 
            3. Edge case where n is 1 should have 0 as result. Since we have started the recursion with 2nd level where we pass the clip as 1 instead of 0 as that's the only way to go from the first level.
            
        Time: O(N^2)
        Space: O(N^2)
    */
    int n;
    vvi cache;
    int util(int curr, int clip) {
        if (curr >= n) {
            if (curr == n) {
                cache[curr][clip] = 0;
                return 0;
            }
            return 10001;
        }
        if (cache[curr][clip] != -1) return cache[curr][clip];
        
        return cache[curr][clip] = min(util(curr + clip, clip) + 1, util(curr + curr, curr) + 2);
    }
    int minSteps(int n) {
        this->n = n;
        cache = vvi (n + 1, vi (n + 1, -1));
        if (n == 1) return 0;
        return 1 + util(1, 1);     
    }
};