class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-2;
        // Find the first non-increasing value from the right of the array
        while (right >= 0 && nums[right + 1] <= nums[right]) right--;

        // Record the current right to left, shift right to the rightmost
        left = right;
        right = n-1;
        
        // If left has reached to the starting, there is no point swapping, just reverse the whole array
        // else
        if (left >= 0) {
            // Keep bringing right closer as long as the right value isn't greater than left val
            while (nums[right] <= nums[left]) right--;

            
            // Once found, swap them, 
            swap(nums[left], nums[right]);
        }
        
        // At last reverse them
        reverseArr(nums, left+1);
        
    }
    void reverseArr(vector<int>& nums, int start) {
        int left = start;
        int right = nums.size() - 1;
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};