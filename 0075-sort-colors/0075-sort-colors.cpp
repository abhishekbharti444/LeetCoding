class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int first = 0;
        int second = 0;
        int last = n-1;
        
        while (second <= last) {
            if (nums[second] == 0) {
                swap(nums[first], nums[second]);
                first++;
                second++;
            }
            else if (nums[second] == 1) {
                second++;
            }
            else {
                swap(nums[second], nums[last]);
                last--;
            }
        }
    }
};