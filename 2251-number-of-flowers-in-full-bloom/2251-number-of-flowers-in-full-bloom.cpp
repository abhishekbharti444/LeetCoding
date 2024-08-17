class Solution {
public:
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