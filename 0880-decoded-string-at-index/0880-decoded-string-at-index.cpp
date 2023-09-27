class Solution {
public:
    /*
        Read the question carefully, it doesn't say you can take decimal number, 
        so if leet22code is there, it doesn't mean you can have leet 22 times, 
        instead you have to take leet 2 times once, and then 2 times again.
        
        
        Approach:
            1. First try to calculate the total count of characters that should 
                be there in s after decoding. first loop takes care of this.
            2. Now start from the end, and do the reverse process
                a. If at any moment we find total_count less than k, we can just take
                    the remainder of it with total_count.
                b. if k becomes 0 and that char is not a digit, this is our result.
                c. Then decrement total_count accordingly.
            
        Time: O(N)
        Space: O(1)
    */
    string decodeAtIndex(string s, int k) {
        int n = s.size();
        long long total_count = 0;
        
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                total_count *= s[i] - '0';
            }
            else total_count++;
        }
        
        for (int i = n-1; i >= 0; --i) {
            k %= total_count;
            if (k == 0 && !isdigit(s[i])) return (string) "" + s[i];
            
            if (isdigit(s[i])) {
                total_count /= s[i] - '0';
            }
            else total_count--;
        }
        return "";
    }
};