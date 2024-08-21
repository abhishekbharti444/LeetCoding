#define vi vector<int>
#define vvi vector<vi>
class Solution {
public:

    
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