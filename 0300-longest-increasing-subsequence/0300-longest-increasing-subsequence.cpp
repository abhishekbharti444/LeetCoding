class Solution {
public:
    /*
        Approach : Binary search(Awesome trick)
            1. Take a vector which will contain the elements always in increasing order 
                and when an element is encountered which is smaller than the last guy in this vector, 
                we will replace one smaller element present in vec with this by doing the binary search of new element
                in the existing vec elements.
            2. If curr elem is greater than last elem of vec, we safely push_back in vec marking addition of length of LIS.
            3. If curr elem is not greater than vec[last], we need to find curr suitable location
                in the vec(doing binary search for curr in vec) and replace the old value with the curr value. 
                This would work because we are taking a greater value than curr and 
                making it smaller by replacing it with curr without breaking the increasing subsequence order.
            4. At last return the size of the vec, as these are the numbers that form the LIS with lowest numbers possible.
    */
    int lengthOfLIS(vector<int>& nums) {
        vector<int> vec;
        int n = nums.size();
        vec.push_back(nums[0]);
        for (int i = 1; i < n; ++i) {
            int last = vec.back();
            if (nums[i] > last) vec.push_back(nums[i]);
            else {
                // Find nums[i] location in vec with binary search and replace it with new val
                int index = lower_bound(vec.begin(), vec.end(), nums[i]) - vec.begin();
                vec[index] = nums[i];
            }
        }
        return vec.size();
    }
};