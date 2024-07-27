class Solution {
public:
    
    map<char, string> mp;

    
    vector<string> res;
    int n;
    string digits;
    void util(int index, string& comb) {
        if (index == n) {
            res.push_back(comb);
            return;
        }
        
        string str = mp[digits[index]];
        for (int i = 0; i < str.size(); ++i) {
            comb.push_back(str[i]);
            util(index + 1, comb);
            comb.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        this->digits = digits;
        n = digits.size();
        if (n == 0) return res;
        string comb;
        util(0, comb);
        return res;
    }
};