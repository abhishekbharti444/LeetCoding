class Solution {
public:
    /*
        Great question on sliding window. 
        Approach: 
        1. Store the freq of each char so far in a map. 
        2. Store the maximum freq which is maximum number of times a char has occured so far. 
        3. If the window size - max_freq  are greater than given k, we need to reduce the window from the left. 
            3a. For that we need to remove the entry of left char from the map and increment left. 
        4. Store a potential window size by taking maximum from a global result. 
    
    */
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        int right = 0;
        
        int max_freq = 0;
        
        unordered_map<char, int> mp;
        int res = 0;
        while (right < n) {
            mp[s[right]]++;
            max_freq = max(max_freq, mp[s[right]]);
            
            while ((right - left + 1) - max_freq > k) {
                mp[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
        
    }
};