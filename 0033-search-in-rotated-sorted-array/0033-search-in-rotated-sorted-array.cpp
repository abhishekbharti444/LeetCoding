class Solution {
public:
    
       /*
        Approach :   If a sorted array is shifted, if you take the middle, always one side will be sorted. Take the recursion according to that rule.
    
        1- take the middle and compare with target, if matches return.
        2- if middle is bigger than left side, it means left is sorted
        2a- if [left] < target < [middle] then do recursion with left, middle - 1 (right)
        2b- left side is sorted, but target not in here, search on right side middle + 1 (left), right
        3- if middle is less than right side, it means right is sorted
        3a- if [middle] < target < [right] then do recursion with middle + 1 (left), right
        3b- right side is sorted, but target not in here, search on left side left, middle -1 (right)
        
    */ 
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (nums[mid] == target) return mid;
            if (target == nums[low]) return low;
            if (target == nums[high]) return high;
            if (nums[mid] > nums[low]) {
                if (target > nums[low] && target < nums[mid]) high = mid-1;
                else low = mid+1;
            }
            else {
                if (target > nums[mid] && target < nums[high]) low = mid + 1;
                else high = mid - 1;
            }
        }
        return -1;
    }
};