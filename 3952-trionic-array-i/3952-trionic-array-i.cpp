class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int index = 1;
        while (index < n && nums[index] > nums[index - 1]) {
            index++;
        }
        if (index == 1) return false;
        int first = index;
        while (index < n && nums[index] < nums[index - 1]) {
            index++;
        }
        if (first == index) return false;
        int second = index;
        while (index < n && nums[index] > nums[index-1]) {
            index++;
        }
        if (index == second) return false;
        return index == n;
    }
};