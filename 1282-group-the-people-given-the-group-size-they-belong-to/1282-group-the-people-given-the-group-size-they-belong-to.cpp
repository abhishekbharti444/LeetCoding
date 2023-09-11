class Solution {
public:
    /*
        Create a hashmap for size versus all the elements for that size
        Check who all should be put into that size vector.
        submission number 6
    */
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> res;
        map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[groupSizes[i]].push_back(i);
        }
        
        for (auto& el : mp) {
            int count = el.first;
            int total = el.second.size();
            int k = total/count;
            int index = 0;
           
            while (k--) {
                vector<int> curr;
                for (int i = 0; i < count; ++i) curr.push_back(el.second[index++]);
                res.push_back(curr);
            }
        }
        return res;
    }
};