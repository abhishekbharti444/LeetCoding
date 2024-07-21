class Solution {
public:
    vector<string> res;
    int total;
    void util(int left_count, int right_count, string& curr) {
        if (left_count < right_count || left_count > total || right_count > total) return;
        if (left_count == total && right_count == total) {
            // capture a result
            res.push_back(curr);
            return;
        }
        // Only one choice to include
        if (left_count == right_count) {
            curr += '(';
            util(left_count+1, right_count, curr);
            curr.pop_back();
        }
        
        // Both choices to include
        if (left_count > right_count) {
            curr += '(';
            util(left_count + 1, right_count, curr);
            curr.pop_back();
            curr += ')';
            util(left_count, right_count + 1, curr);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        total = n;
        util(0, 0, curr);
        return res;
    }
};