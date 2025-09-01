class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        // This question can be rephrased as 
        // Find the largest subarray of the sorted of nums such that 
        // min_el * k >= max_el

        vector<int> A = nums;
        sort(A.begin(), A.end());

        int left = 0;
        int right = 0;
        int res = 0;
        while (right < n) {
            while (left < n && left < right && (long long)(A[left] * (long long)k) < (long long)A[right]) {
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return n - res;
    }
};