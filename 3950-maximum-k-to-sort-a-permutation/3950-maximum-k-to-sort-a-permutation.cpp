
class Solution {
public:
/*
Approach:
---------
We are allowed to swap nums[i] and nums[j] if (nums[i] & nums[j]) == k.
We need the maximum such k that allows us to sort the array.

Key insight:
- Only the misplaced numbers (nums[i] != i) actually need to move.
- If we take the bitwise AND of all these misplaced numbers, we get the largest k
  that is common to all of them.
- This k ensures that each misplaced number shares these common bits,
  so they can always be repositioned (possibly by involving correctly placed numbers as bridges).
- If the array is already sorted (no misplaced numbers), we should return 0.

Steps:
1. Initialize mask = INT_MAX (all bits set).
2. For each index i:
     - If nums[i] != i → element is misplaced → update mask &= nums[i].
3. If no element was misplaced, mask remains INT_MAX → return 0.
   Otherwise, return mask (the AND of all misplaced numbers).
*/

    int sortPermutation(vector<int>& nums) {
        int mask = INT_MAX;  // start with all bits = 1
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) {
                mask &= nums[i];  // shrink mask to keep only common bits
            }
        }

        // If mask was never updated (array already sorted), return 0.
        // Otherwise return the AND of misplaced numbers.
        return mask == INT_MAX ? 0 : mask;
    }
};
