class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int res = 0;
        while (low <= high) {
            int mid = low + (high - low)/2;


            if (nums[mid] > nums[mid + 1]) {// Check for a potential result
                res = mid + 1;
                break;
            }
            // Check if left side is sorted
            if (nums[mid] > nums[n-1]) {
                // The result should lie in the right side
                low = mid + 1;
            }
            else {// if right side is sorted
                high = mid - 1; // The result must lie in the left side
            } 
        }
        return nums[res];
    }
};