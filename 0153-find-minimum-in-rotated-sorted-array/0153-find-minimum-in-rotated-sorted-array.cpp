class Solution {
public:
    /*
        If I do a binary search; the condition to find the minimum would be in the right side
            if elem at mid is greater than last element
        it'll be in the left side 
            if elem at mid is smaller than first element
    */
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int low = 0;
        int high = n-1;
        int index = 0;
        while (low <= high) {
            int mid = low + (high - low)/2;
            
            // Capture the index if two consecutive elements are out of order.
            if (nums[mid] > nums[mid + 1]) {
                index = mid + 1;
                break;
            }
            
            // Compare mid with the last elem, if nums[mid] is bigger, the result has to lie in the right side.
            if (nums[mid] > nums[n-1]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return nums[index];
    }
};