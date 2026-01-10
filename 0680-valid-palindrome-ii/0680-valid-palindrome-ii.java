/**
 * Approach: Two Pointers with One Deletion
 *
 * Key insight: A string can form a palindrome after deleting at most one character
 * if when we find the first mismatch, removing either the left or right character
 * results in a valid palindrome for the remaining substring.
 *
 * Algorithm:
 * 1. Use two pointers from both ends moving inward
 * 2. If characters match, continue moving pointers
 * 3. If mismatch found, try two options:
 *    - Skip left character and check if rest is palindrome
 *    - Skip right character and check if rest is palindrome
 * 4. Return true if either option works
 *
 * Time: O(n) - at most two passes through the string
 * Space: O(1) - only using pointers
 */
class Solution {
    // Helper method to check if substring is a valid palindrome
    public boolean validPalindromeUtil(String s, int left, int right) {
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) return false;
            left++;
            right--;
        }
        return true;
    }

    public boolean validPalindrome(String s) {
        int n = s.length();
        int left = 0;
        int right = n - 1;

        // Check palindrome with two pointers
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                // Found mismatch: try removing either left or right character
                return validPalindromeUtil(s, left + 1, right) ||
                       validPalindromeUtil(s, left, right - 1);
            }
            left++;
            right--;
        }

        // No mismatches found - already a palindrome
        return true;
    }
}