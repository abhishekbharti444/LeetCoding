class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        
        while (left < right) {
            if (nums[left] % 2 == 0) {
                left++;
                continue;
            }
            if (nums[right] % 2 == 1) {
                right--;
                continue;
            }
            
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
        return nums;
    }
};