class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0; 
        int right = n-1;
        int leftMax = 0;
        int rightMax = 0;
        int res = 0;
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (leftMax < rightMax) {
                res += leftMax - height[left];
                left++;
            }
            else {
                res += rightMax - height[right];
                right--;
            }
        }
        return res;
    }
};