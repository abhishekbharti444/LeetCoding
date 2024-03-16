class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> arr;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) arr.push_back(-1);
            else arr.push_back(1);
        }
        
        unordered_map<int, int> mp;
        int index = 0;
        int curr_sum = 0;
        int res = 0;
        mp[0] = -1;
        while (index < n) {
            curr_sum += arr[index];
            if (mp.find(curr_sum) != mp.end()) {
                res = max(res, (index - mp[curr_sum]));
            }
            else {
                mp[curr_sum] = index;
            }
            index++;
        }
        return res;
    }
};