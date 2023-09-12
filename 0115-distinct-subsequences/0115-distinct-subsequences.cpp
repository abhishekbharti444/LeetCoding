class Solution {
public:
    string s, t;
    vector<vector<int>> memo;
    int util(int sIndex, int tIndex) {
        if (tIndex < 0) {
            return 1;
        }
        if (sIndex < 0) {
            return 0;
        }
        
        if (memo[sIndex][tIndex] != -1) {
            return memo[sIndex][tIndex];
        }
        
        int res = 0;
        if (s[sIndex] == t[tIndex]) {
            res = util(sIndex - 1, tIndex) + util(sIndex - 1, tIndex - 1);
        }
        else {
            res = util(sIndex - 1, tIndex);
        }
        return memo[sIndex][tIndex] = res;
        
    }
    int numDistinct(string s, string t) {
        this->s = s;
        this->t = t;
        memo = vector<vector<int>> (s.size() + 1, vector<int> (t.size()+1, -1));
        return util(s.size()-1, t.size()-1);
    }
};