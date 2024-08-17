class Solution {
public:
    /*
        Approach: 
            1. Increment the value of the start of the interval, decrement the value of 1 + end of the interval. 
            2. Take another map where you can store the prefix_sum value for each key.
            3. For each query, find the upper bound in the second map of that query,
                3a. If this iterator is begin of the second map, then this key doesn't hold any flowers. Push 0 to the result and continue.
                3b. Else, decrement the iterator to get the number of flowers bloomed till that day. 
            4. Capture the result and return. 
            
        Time: O(NLogN) + O(MLogN), N => flowers.size(), M => people.size();
    */
    
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> mp, mp1;
        
        for (int i = 0; i < flowers.size(); ++i) {
            mp[flowers[i][0]]++;
            mp[flowers[i][1]+1]--;
        }
        int n = flowers.size();
        int curr = 0;
        vector<int> res;
        for (auto& a: mp) {
            curr += a.second;
            mp1[a.first] = curr;
            // cout<<a.first<<" "<<curr<<endl;
        }
        
        for (int i = 0; i < people.size(); ++i) {
            auto itr = mp1.upper_bound(people[i]);
            if (itr == mp1.begin()) {
                res.push_back(0);
                continue;
            }
            itr--;

            // cout<<itr->first<<" "<<itr->second<<endl;
            res.push_back(itr->second);
        }
        return res;
    }
};