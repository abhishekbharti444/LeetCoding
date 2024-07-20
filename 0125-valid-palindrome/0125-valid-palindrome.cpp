class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string temp = "";
        for (int i = 0; i < n; ++i) {
            // if (isalpha(s[i])) curr += s[i];
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) temp += tolower(s[i]);
        }
        int left = 0; 
        int right = temp.size() - 1;
        while (left < right) {
            if (temp[left] != temp[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
