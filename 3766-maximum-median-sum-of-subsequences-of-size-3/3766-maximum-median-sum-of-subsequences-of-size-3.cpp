class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        vector<int> A = nums;
        int n = A.size();
        sort(A.begin(), A.end());

        int left = 0;
        int right = n-1;
        long long res = 0;
        while (right - left + 1 >= 3) {
            res += A[right - 1];
            left += 1;
            right -= 2;
        }
        return res;
    }
};