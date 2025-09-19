class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (nums[mid] == target) return mid;
            if (nums[low] == target) return low;
            if (nums[high] == target) return high;
            // Left side is sorted
            if (nums[mid] > nums[low]) {
                // Check if target in the left section
                if (nums[low] < target && target < nums[mid]) 
                    high = mid - 1;
                else // If target is in the right side
                    low = mid + 1;
            }
            else {// Right side is sorted
                // Check if target is in the right section, go to the right side
                if (nums[mid] < target && target < nums[high]) {
                    low = mid + 1;
                }
                else high = mid - 1;// Browse in the left side.
            }
        }
        return -1;
    }
};